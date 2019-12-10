function solve(state, row, col) {
  // best cost is itself
  if (row === 0) return state.cost[row][col]
  if (!state.dp.hasOwnProperty(row) || !state.dp[row].hasOwnProperty[col]) {
    state.dp[row] = state.dp[row] || {}
    let best = -1;
    for (let j = 0; j < state.cost[0].length; j += 1) {
      if (j !== col) {
        best = Math.max(best, solve(state, row - 1, j))
      }
    }
    state.dp[row][col] = state.cost[row][col] + best
  }
  return state.dp[row][col]
}

function main(state) {
  let best = -1;
  for (let j = 0; j < state.cost[0].length; j += 1) {
    best = Math.max(best, solve(state, state.cost.length - 1, j))
  }
  return best;
}

console.log(main({
  cost: [
    [6, 2, 3, 2, 1],
    [6, 4, 1, 2 ,3],
    [1, 2, 3, 4, 5],
  ],
  dp: {}
}));
