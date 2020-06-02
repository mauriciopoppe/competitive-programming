from typing import List

from test_framework import generic_test


def next_permutation(perm: List[int]) -> List[int]:
    j = len(perm) - 1
    while j - 1 >= 0 and perm[j - 1] >= perm[j]:
        j -= 1

    if j == 0:
        return []

    low = len(perm) - 1
    while perm[low] <= perm[j - 1]:
        low -= 1

    perm[j - 1], perm[low] = perm[low], perm[j - 1]
    perm[j:] = sorted(perm[j:])
    return perm

if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('next_permutation.py',
                                       'next_permutation.tsv',
                                       next_permutation))
