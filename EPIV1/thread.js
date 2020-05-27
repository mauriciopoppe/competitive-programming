var n_odd = 1;
var n_even = 0;

function even(fn) {
  var step = Math.random() * 3 * 1000;
  setTimeout(function () {
    console.log('even step, time=%d, number=%d', step, n_even);
    fn(n_even);
    n_even += 2;
  }, step);
}
function odd(fn) {
  var step = Math.random() * 3 * 1000;
  setTimeout(function () {
    console.log('odd step, time=%d, number=%d', step, n_odd);
    fn(n_odd);
    n_odd += 2;
  }, step);
}

function solve() {
  recurse_async(0);
}

function recurse_async(step) {
  function print_number(number) {
    if (number < 10) {
      recurse_async(step + 1);
    }
  }

  if (step % 2 !== 0) {
    odd(print_number);
  } else {
    even(print_number);
  }
}

solve();