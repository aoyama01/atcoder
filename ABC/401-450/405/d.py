# 幅優先探索？深さ優先？
# 行きがけ順だけ考える
# そもそも無向グラフ
# 最短経路だからDPも必要？
from collections import deque

h, w = map(int, input().split())
s = [list(input()) for _ in range(h)]

dist = [[-1] * w for _ in range(h)]
arrow = [[""] * w for _ in range(h)]

# 逆向きのBFSを行う
# 非常口を探索キューにメモ
queue = deque()
for i in range(h):
    for j in range(w):
        if s[i][j] == "E":
            queue.append((i, j))
            dist[i][j] = 0
# BFS実行
while queue:
    x, y = queue.popleft()
    for dx, dy, dir_arrow in [(-1, 0, "v"), (1, 0, "^"), (0, -1, ">"), (0, 1, "<")]:
        nx, ny = x + dx, y + dy
        if 0 <= nx < h and 0 <= ny < w:
            if s[nx][ny] == "." and dist[nx][ny] == -1:
                dist[nx][ny] = dist[x][y] + 1
                arrow[nx][ny] = dir_arrow
                queue.append((nx, ny))

# 出力
for i in range(h):
    row = ""
    for j in range(w):
        if s[i][j] == ".":
            row += arrow[i][j]
        else:
            row += s[i][j]
    print(row)
