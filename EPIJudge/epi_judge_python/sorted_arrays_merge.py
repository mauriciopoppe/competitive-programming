from typing import List
import heapq
from test_framework import generic_test


def merge_sorted_arrays(sorted_arrays: List[List[int]]) -> List[int]:
    ind = [0] * len(sorted_arrays)
    q = []
    for i in range(len(sorted_arrays)):
        heapq.heappush(q, (sorted_arrays[i][0], i))

    ans = []
    while len(q):
        x, i = heapq.heappop(q)
        ans.append(x)
        ind[i] += 1
        if ind[i] < len(sorted_arrays[i]):
            heapq.heappush(q, (sorted_arrays[i][ind[i]], i))

    return ans



if __name__ == '__main__':
    exit(
        generic_test.generic_test_main('sorted_arrays_merge.py',
                                       'sorted_arrays_merge.tsv',
                                       merge_sorted_arrays))
