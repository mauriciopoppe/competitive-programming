function matchSingle(p, q) {
  // console.log(`match: "${p}" "${q}"`);
  if (q[0] === ".") return true;
  return p[0] === q[0];
}

function regex(string, pattern) {
  if (pattern.length === 0 && string.length === 0) return true;
  if (pattern.length === 0) return false;
  // match *
  if (pattern.length >= 2 && pattern[1] === "*") {
    while (true) {
      const match = regex(string, pattern.substring(2));
      if (match) return true;
      if (string.length === 0) break;
      string = string.substring(1);
    }
  } else if (matchSingle(string, pattern)) {
    return regex(string.substring(1), pattern.substring(1));
  }
  return false;
}

function assert(string, pattern) {
  const test = regex(string, pattern);
  if (!test) console.log(`${string} !== ${pattern}`);
  else console.log(`${string} === ${pattern}`);
}

assert("ray", ".*")
assert("ray", "ray.*")
assert("ray", ".*ray")
assert("ray", "...")
assert("ray", ".*")
assert("ray", ".*.*.*.*")
assert("ray", "..y")
assert("chat", ".*ate")
