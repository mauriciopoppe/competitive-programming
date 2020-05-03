from copy import deepcopy
sol = []


def bellman_ford(matrix):
    n = len(matrix)
    d = deepcopy(matrix)

    for k in range(n):
        for i in range(n):
            for j in range(n):
                if d[i][k] + d[k][j] < d[i][j]:
                    d[i][j] = d[i][k] + d[k][j]

    # additional check for negative cycles
    for k in range(n):
        for i in range(n):
            for j in range(n):
                if d[i][k] + d[k][j] < d[i][j]:
                    return False

    return d


def answer(times, time_limit):
    d = bellman_ford(times)
    if not d:
        v = [i for i in range(len(times) - 2)]
        return v

    global sol
    sol = []
    v = []

    def check(v, sum):
        global sol
        if sum >= 0 and len(v) > len(sol):
            sol = deepcopy(v)

    def rec(prev, v, sum):
        n = len(d)
        check(v, sum - d[prev][n - 1])
        for i in range(1, n - 1):
            if v.count(i) == 0:
                v.append(i)
                rec(i, v, sum - d[prev][i])
                v.pop()

    rec(0, v, time_limit)
    sol.sort()
    return [v - 1 for v in sol]
