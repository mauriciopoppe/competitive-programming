INF = 10000000


def edmonds_karp(graph, source, target):
    flow = 0
    while True:
        parent = [-1] * len(graph)
        q = [source]
        while len(q):
            x = q.pop()
            if x == target:
                break
            for y, w in graph[x].items():
                if parent[y] == -1 and w > 0:
                    parent[y] = x
                    q.insert(0, y)
        if parent[target] == -1:
            return flow
        # min weight edge
        minw = INF
        y = target
        while y != source:
            minw = min(minw, graph[parent[y]][y])
            y = parent[y]
        flow += minw
        # adjust flow
        y = target
        while y != source:
            p = parent[y]
            graph[p][y] -= minw
            if graph[p][y] <= 0:
                graph[p].pop(y)
            if p not in graph[y]:
                graph[y][p] = 0
            graph[y][p] += minw
            y = p


def answer(entrances, exits, paths):
    source = 0
    target = len(paths) + 1
    graph = [{} for i in range(len(paths) + 2)]
    # source
    for e in entrances:
        graph[0][e + 1] = INF
    # paths
    for i in range(len(paths)):
        for j in range(len(paths[0])):
            if paths[i][j]:
                # all paths moved because of the source
                graph[i + 1][j + 1] = paths[i][j]
    # target
    for e in exits:
        graph[e + 1][len(paths) + 1] = INF

    return edmonds_karp(graph, source, target)


entrances = [0, 1]
exits = [4, 5]
paths = [
    [0, 0, 4, 6, 0, 0],
    [0, 0, 5, 2, 0, 0],
    [0, 0, 0, 0, 4, 4],
    [0, 0, 0, 0, 6, 6],
    [0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 0]
]
print(answer(entrances, exits, paths))
