def addToAns(row, ans):
    t = 0
    b = 0
    for i in range(len(row)):
        t = t * 2 + row[i][0]
        b = b * 2 + row[i][1]
    if t not in ans:
        ans[t] = []
    ans[t].append(b)


def pred(ans, row, cand, k):
    if k == len(row):
        addToAns(cand, ans)
    else:
        for i in range(2):
            for j in range(2):
                if len(cand) == 0:
                    cand.append([i, j])
                    pred(ans, row, cand, k)
                    cand.pop()
                else:
                    last = cand[-1]
                    total = last[0] + last[1] + i + j
                    if (total == 1 and row[k]) or (total != 1 and not row[k]):
                        cand.append([i, j])
                        pred(ans, row, cand, k + 1)
                        cand.pop()


def ldag(graph):
    d = {}
    for k, v in graph[0].items():
        d[k] = len(v)
    for j in range(1, len(graph)):
        nd = {k: 0 for k in graph[j]}
        for k, v in graph[j].items():
            for it in v:
                if it in d:
                    nd[k] += d[it]
        d = nd

    total = 0
    for k, v in d.items():
        total += v
    return total


def answer(g):
    nr = len(g)
    nc = len(g[0])
    graph = [{} for j in range(nc)]

    for j in range(nc):
        col = []
        for i in range(nr):
            col.append(g[i][j])
        pred(graph[j], col, [], 0)

    return ldag(graph)


def runner():
    g = [[True, False, True], [False, True, False], [True, False, True]]
    assert answer(g) == 4

    g = [[True, False, True, False, False, True, True, True],
         [True, False, True, False, False, False, True, False],
         [True, True, True, False, False, False, True, False],
         [True, False, True, False, False, False, True, False],
         [True, False, True, False, False, True, True, True]]
    assert answer(g) == 254

    g = [[True, True, False, True, False, True, False, True, True, False],
         [True, True, False, False, False, False, True, True, True, False],
         [True, True, False, False, False, False, False, False, False, True],
         [False, True, False, False, False, False, True, True, False, False]]
    assert answer(g) == 11567


if __name__ == '__main__':
    runner()
