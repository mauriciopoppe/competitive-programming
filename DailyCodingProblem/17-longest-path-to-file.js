/**
 * Returns true if the char at i is a control char
 *
 * @param {string} sentence
 * @param {int} i
 */
function isControl(sentence, i) {
  return sentence[i] === "\\";
}

/**
 * Returns true if the char at i is a tab
 *
 * @param {string} sentence
 * @param {int} i
 */
function isTab(sentence, i) {
  return sentence[i] === "\\" && sentence[i + 1] === "t";
}

/**
 * @param {string} word
 * @return An object with the following info
 *
 * { token: string, isFile: boolean }
 */
function getNextToken(sentence, i) {
  let isFile = false;
  let token = "";
  while (i < sentence.length && sentence[i] !== "\\") {
    if (sentence[i] === ".") isFile = true;
    token += sentence[i];
    i += 1;
  }
  return { token, isFile };
}

function solve(sentence) {
  const folderLength = [];
  let best = 0;
  let i = 0;
  while (i < sentence.length) {
    let total = 0;
    let j = 0;
    while (isControl(sentence, i)) {
      // 1 for the / after the folder
      if (isTab(sentence, i)) total += folderLength[j++] + 1;
      i += 2;
    }
    const desc = getNextToken(sentence, i);
    if (desc.isFile) {
      total += desc.token.length;
      best = Math.max(best, total);
    } else {
      folderLength[j] = desc.token.length;
    }
    // console.log(j, desc, best);
    i += desc.token.length;
  }
  return best;
}

const sentence =
  "dir\\n\\tsubdir1\\n\\t\\tfile1.ext\\n\\t\\tsubsubdir1\\n\\tsubdir2\\n\\t\\tsubsubdir2\\n\\t\\t\\tfile2.ext";
console.log(solve(sentence));
