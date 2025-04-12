# https://qiita.com/drken/items/4a7869c5e304883f539b
# 深さ優先探索(DFS)
def dfs(G, v, visited):
    visited[v] = True  # 頂点 v を訪問済にする

    for to, weight in G[v]:
        if not visited[to]:
            dfs(G, to, visited)


# 頂点数 N, 辺数 M を読み取る
N, M = map(int, input().split())

# 重み付き有向グラフを構築
G = [[] for _ in range(N)]
for _ in range(M):
    from_node, to_node, weight = map(int, input().split())
    # 辺を (行き先, 重み) のタプルで表現する
    G[from_node].append((to_node, weight))  # 有向辺なら片方向のみ
    # G[from_node].append((to_node, weight))  # 無向辺ならこれも追加

# 訪問フラグの初期化と DFS の実行
visited = [False] * N
dfs(G, 0, visited)  # 頂点 0 から探索開始

# （必要なら）訪問済みの頂点一覧を出力
# print(visited)
