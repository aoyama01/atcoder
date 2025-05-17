from collections import defaultdict

h, w, n = map(int, input().split())

row_map = defaultdict(set)  # 行ごとのゴミの集合
col_map = defaultdict(set)  # 列ごとのゴミの集合

for i in range(n):
    x, y = map(int, input().split())
    row_map[x].add(y)
    col_map[y].add(x)

q = int(input())
for i in range(q):
    type, v = map(int, input().split())

    if type == 1:
        # 行 v のゴミ数を出力
        print(len(row_map[v]))
        # ゴミを削除
        for y in row_map[v]:
            col_map[y].discard(v)
        row_map[v].clear()
    else:
        # 列 v のゴミ数を出力
        print(len(col_map[v]))
        # ゴミを削除
        for x in col_map[v]:
            row_map[x].discard(v)
        col_map[v].clear()
