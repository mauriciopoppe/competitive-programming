from test_framework import generic_test
import math
from collections import defaultdict

def fact(coef, n, op):
    for k in range(2, int(math.sqrt(n) + 1)):
        while n and n % k == 0:
            coef[k] += op
            n /= k
    if n:
        coef[n] += op


def compute_binomial_coefficient(n: int, k: int) -> int:
    coef = defaultdict(int)

    den = max(n - k, k)
    num = n - den

    for i in range(num + 1, n + 1):
        fact(coef, i, 1)

    for i in range(2, den + 1):
        fact(coef, i, -1)

    mult = 1
    for b, e in coef.items():
        mult *= int(pow(b, e))
    return mult


if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('binomial_coefficients.py',
                                       'binomial_coefficients.tsv',
                                       compute_binomial_coefficient))
