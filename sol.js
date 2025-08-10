const readline = require("readline");

const m = 1000000007;

function best(n) {
  const dp = new Array(n + 1).fill(0);
  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 2;
  dp[3] = 4;
  dp[4] = 8;
  dp[5] = 16;
  dp[6] = 32;

  for (let i = 7; i <= n; i++) {
    dp[i] =
      ((dp[i - 1] % m) +
        (dp[i - 2] % m) +
        (dp[i - 3] % m) +
        (dp[i - 4] % m) +
        (dp[i - 5] % m) +
        (dp[i - 6] % m)) %
      m;
  }

  console.log(dp[n] % m);
}

// Read input from stdin
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
  terminal: false,
});

let inputLines = [];
rl.on("line", (line) => {
  inputLines.push(line.trim());
});

rl.on("close", () => {
  let t = 1; // You can update this if multiple test cases are used
  let lineIndex = 0;
  while (t--) {
    const n = parseInt(inputLines[lineIndex++]);
    best(n);
  }
});
