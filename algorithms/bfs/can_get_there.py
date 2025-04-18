# sからtへ辿り着けるか
from collections import deque

# 頂点数と辺数、s と t を入力
N, M, s, t = map(int, input().split())

# グラフ入力受取（隣接リスト）
G = [[] for _ in range(N)]
for _ in range(M):
    a, b = map(int, input().split())
    G[a].append(b)

# 幅優先探索(BFS)で頂点 s から t まで到達できるか判定
# 頂点 s からの距離を全長点について計算
s = 0  # スタート地点
t = 1  # ゴール地点
dist = [-1] * N
que = deque()
dist[s] = 0
que.append(s)

# キューが空になるまで探索を続ける
while que:
    v = que.popleft()  # 未探索の頂点を取り出す
    # 隣接する頂点を全て探索する
    for nv in G[v]:
        # 未探索の頂点のとき
        if dist[nv] == -1:
            dist[nv] = dist[v] + 1  # 距離を更新
            que.append(nv)  # キューに追加

# s から t に辿り着けるかどうかを出力
if dist[t] != -1:
    print("Yes")
else:
    print("No")

# 幅優先探索(BFS)で無向グラフの連結成分の個数を数える
dist = [-1] * N
que = deque()
cnt = 0  # 連結成分の個数

for i in range(N):
    if dist[i] != -1:
        continue  # 既に訪問済みの頂点はスキップ

    # 新しい連結成分の探索開始
    dist[i] = 0
    que.append(i)

    while que:
        v = que.popleft()  # 未探索の頂点を取り出す
        # 隣接する頂点を全て探索する
        for nv in G[v]:
            # 未探索の頂点のとき
            if dist[nv] == -1:
                dist[nv] = dist[v] + 1  # 距離を更新
                que.append(nv)  # キューに追加

    cnt += 1

print(cnt)


# 幅優先探索(BFS)で二部グラフかどうかを判定する
# 以下2つの記述は同値
# - G は二部グラフである
# - dist の値が等しい頂点同士が隣接することはない
dist = [-1] * N
que = deque()
is_bipartite = True  # 二部グラフであるかどうか

for i in range(N):
    if dist[i] != -1:
        continue  # 既に訪問済みの頂点はスキップ

    # 新しい連結成分の探索開始
    dist[i] = 0
    que.append(i)

    while que:
        v = que.popleft()  # 未探索の頂点を取り出す
        # 隣接する頂点を全て探索する
        for nv in G[v]:
            # 未探索の頂点のとき
            if dist[nv] == -1:
                dist[nv] = dist[v] + 1  # 距離を更新
                que.append(nv)  # キューに追加
            else:
                # 整合性の確認
                if dist[nv] == dist[v]:
                    is_bipartite = False  # 二部グラフでない
                    # print("No")
                    # exit()

# 二部グラフかどうか
print("Yes" if is_bipartite else "No")


###


# 頂点数 N, 辺数 M を読み取る
N, M = map(int, input().split())

# グラフ入力受取（隣接リスト）
G = [[] for _ in range(N)]
for _ in range(M):
    from_node, to_node, weight = map(int, input().split())
    # 頂点を 0-indexed に変換
    from_node -= 1
    to_node -= 1
    # 辺を (行き先, 重み) のタプルで表現する
    G[from_node].append((to_node, weight))  # 有向辺なら片方向のみ
    # G[from_node].append((to_node, weight))  # 無向辺ならこれも追加


# 深さ優先探索(DFS)で頂点 s から t まで到達できるか判定
def dfs(G, v, visited):
    visited[v] = True  # 頂点 v を訪問済にする

    for to, weight in G[v]:
        if not visited[to]:
            dfs(G, to, visited)


# 訪問フラグの初期化と DFS の実行
s = 0  # スタート地点
t = 1  # ゴール地点
visited = [False] * N  # 全頂点を「未訪問」に初期化
dfs(G, s, visited)  # 頂点 s から探索開始

# t に辿り着けるかどうか
print("Yes" if visited[t] else "No")

# （必要なら）訪問済みの頂点一覧を出力
# print(visited)
