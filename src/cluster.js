import { Dolos } from "@dodona/dolos-lib";
import { readdir } from "fs/promises";
import path from "path";

import readline from "node:readline/promises";
import { stdin as input, stdout as output } from "node:process";

const rl = readline.createInterface({ input, output });

const mainFile = await rl.question("");
const directoryPath = await rl.question("");

rl.close();

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

    console.log(report.allPairs()[0].similarity);
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

    // Take top 10 matches
    const topMatches = matches.slice(0, 10);

    // Print rightFile paths of top 10 matches
    topMatches.forEach((match) => console.log(match.path));
    // for (const pair of report.allPairs()) {
    //   console.log(pair);
    // }
  } else {
    console.log("No files to compare.");
  }
}

compareFiles(mainFile, directoryPath).catch(console.error);
