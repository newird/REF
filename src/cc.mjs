import { Dolos } from "@dodona/dolos-lib";
import { readdir } from "fs/promises";
import path from "path";


const args = process.argv;
const mainFile = args[2];
const directoryPath = args[3];

async function getFilePaths(dir) {
  try {
    const files = await readdir(dir, { withFileTypes: true });
    return files
      .filter((dirent) => dirent.isFile())
      .map((dirent) => path.join(dir, dirent.name)); // Construct full paths
  } catch (err) {
    console.error("Error reading directory:", err);
    return []; // Return an empty array in case of error
  }
}

async function compareFiles(mainFile, directory) {
  const dolos = new Dolos();
  const filePaths = await getFilePaths(directory);

  // Prepend the main file to the list of files to be analyzed
  filePaths.unshift(mainFile);

  // Proceed with analysis if there are files to compare
  if (filePaths.length > 1) {
    const report = await dolos.analyzePaths(filePaths);
    let matches = [];

    for (const pair of report.allPairs()) {
      if (pair.leftFile.path === mainFile) {
        matches.push({
          similarity: pair.similarity,
          path: pair.rightFile.path,
        });
      }
    }

    // Sort matches by similarity in descending order
    matches.sort((a, b) => b.similarity - a.similarity);

    const topMatches = matches.slice(0, 3);

    topMatches.forEach((match) => {
      console.log(match.path);
      console.log(match.similarity);
    });
  } else {
    console.log("No files to compare.");
  }
}

async function main() {
  const startTime = performance.now();
  try {
    await compareFiles(mainFile, directoryPath);
  } catch (error) {
    console.error(error);
  } finally {
    const endTime = performance.now();
    const executionTime = endTime - startTime;
    console.log(`${executionTime}`);
  }
}

main();
