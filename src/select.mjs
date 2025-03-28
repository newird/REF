import { Dolos } from "@dodona/dolos-lib";
import { readdir, readFile } from "fs/promises";
import path from "path";

// Configuration
const SIMILARITY_THRESHOLD = 0.9; // Adjust as needed
const MIN_CLUSTER_SIZE = 2; // Minimum files to form a cluster

async function getFilePaths(dir) {
  try {
    const files = await readdir(dir, { withFileTypes: true });
    return files
      .filter((dirent) => dirent.isFile())
      .map((dirent) => path.join(dir, dirent.name));
  } catch (err) {
    console.error("Error reading directory:", err);
    return [];
  }
}

async function clusterFiles(directory) {
  const dolos = new Dolos();
  const filePaths = await getFilePaths(directory);

  if (filePaths.length === 0) {
    console.log("No files found in the directory.");
    return;
  }

  const report = await dolos.analyzePaths(filePaths);
  const clusters = {};

  for (const pair of report.allPairs()) {
    if (pair.similarity >= SIMILARITY_THRESHOLD) {
      const file1 = pair.leftFile.path;
      const file2 = pair.rightFile.path;

      // Find existing clusters for the files
      let cluster1 = null;
      let cluster2 = null;

      for (const clusterId in clusters) {
        if (clusters[clusterId].includes(file1)) {
          cluster1 = clusterId;
        }
        if (clusters[clusterId].includes(file2)) {
          cluster2 = clusterId;
        }
      }

      if (cluster1 && cluster2) {
        // Both files are in existing clusters, merge them if different clusters
        if (cluster1 !== cluster2) {
          clusters[cluster1] = [...new Set([...clusters[cluster1], ...clusters[cluster2]])];  // Merge and remove duplicates
          delete clusters[cluster2]; // remove empty cluster.
        }
      } else if (cluster1) {
        // file1 is in a cluster, add file2 to it
        clusters[cluster1].push(file2);
      } else if (cluster2) {
        // file2 is in a cluster, add file1 to it
        clusters[cluster2].push(file1);
      } else {
        // Both files are not in any cluster, create a new cluster
        const newClusterId = `cluster_${Object.keys(clusters).length}`;
        clusters[newClusterId] = [file1, file2];
      }
    }
  }

  // Filter out clusters with fewer than MIN_CLUSTER_SIZE files
  const filteredClusters = Object.fromEntries(
    Object.entries(clusters).filter(([, files]) => files.length >= MIN_CLUSTER_SIZE)
  );

  // Find Representative file
  const representativeFiles = {};

  for (const clusterId in filteredClusters) {
    const files = filteredClusters[clusterId];
    // you can add more complex logic to choose representive file
    // For now we simply use the first file in cluster.
    representativeFiles[clusterId] = files[0];
  }

  // Print results
  for (const clusterId in filteredClusters) {
    console.log(`${filteredClusters[clusterId][0]}`);
  }

}

async function main() {
  const args = process.argv;
  const directoryPath = args[2];

  if (!directoryPath) {
    console.error("Please provide a directory path as an argument.");
    return;
  }

  try {
    await clusterFiles(directoryPath);
  } catch (error) {
    console.error("An error occurred:", error);
  }
}

main();
