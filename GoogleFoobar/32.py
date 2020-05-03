def is_valid(maze, p):
    return p[0] >= 0 and p[1] >= 0 and p[0] < len(maze) and p[1] < len(maze[0])

def dijkstra(maze, start, end):
    dx = [0, -1, 0, 1]
    dy = [1, 0, -1, 0]

    q = []
    q.insert(0, (start, 1))
    d = {}
    d[(start, 1)] = 0

    while len(q):
        p0, w = q.pop()

        # regular push
        for i in range(4):
            p1 = p0[0] + dx[i], p0[1] + dy[i]
            x, y = p1
            if is_valid(maze, p1):
                if w and maze[x][y] and (p1, 0) not in d:
                    q.insert(0, (p1, 0))
                    d[(p1, 0)] = d[(p0, w)] + 1
                elif not maze[x][y] and (p1, w) not in d:
                    q.insert(0, (p1, w))
                    d[(p1, w)] = d[(p0, w)] + 1

    mn = 1000000
    if (end, 0) in d:
        mn = min(mn, d[(end, 0)])
    if (end, 1) in d:
        mn = min(mn, d[(end, 1)])
    return mn + 1

def answer(maze):
    r = len(maze)
    c = len(maze[0])
    return dijkstra(maze, (0, 0), (r - 1, c - 1))

maze = [[0, 1, 1, 0],
        [0, 0, 0, 1],
        [1, 1, 0, 0],
        [1, 1, 1, 0]]
maze = [[0, 0, 0, 0, 0, 0], [1, 1, 1, 1, 1, 0], [0, 0, 0, 0, 0, 0], [0, 1, 1, 1, 1, 1], [0, 1, 1, 1, 1, 1], [0, 0, 0, 0, 0, 0]]
print(answer(maze))
