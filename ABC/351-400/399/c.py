import sys  # noqa
from collections import Counter, defaultdict, deque  # noqa
from copy import deepcopy  # noqa
from itertools import accumulate, combinations, permutations, product  # noqa
from math import gcd  # noqa
from operator import itemgetter  # noqa

# import numpy as np  # noqa
# import scipy as sp  # noqa

sys.setrecursionlimit(10**6)  # 再帰呼び出しの上限を引き上げる


# 深さ優先探索(DFS)
def dfs(G, v, visited):
    visited[v] = True  # 頂点 v を訪問済にする

    for to in G[v]:
        if not visited[to]:
            dfs(G, to, visited)


# 頂点数 N, 辺数 M を読み取る
n, m = map(int, input().split())  # 複数の数値入力を受け取る  # noqa: E741

# グラフを構築
G = [[] for _ in range(n)]
for _ in range(m):
    from_node, to_node = map(int, input().split())
    # 0-indexed に変換
    from_node -= 1
    to_node -= 1
    # 重みがある場合は，辺を (行き先, 重み) のタプルで表現する
    G[from_node].append(to_node)  # 有向辺なら片方向のみ
    G[to_node].append(from_node)  # 無向辺ならこれも追加

# （必要なら）訪問済みの頂点一覧を出力
# print(visited)

# # すべての頂点の次数が2以上
# for i in range(n):
#     if len(G[i]) < 2:
#         1
# # 連結性判定
# component = 0

# hen_num = tyouten - component なら森？
# じゃあ，森にするために削除する辺の最小の個数は，component?


# 訪問フラグの初期化
visited = [False] * n
# 全頂点が訪問済みになるまで探索し，連結成分をカウント
cnt = 0
for i in range(n):
    if not visited[i]:
        dfs(G, i, visited)  # 新しい連結成分を探索
        cnt += 1

# print(cnt)
print(m - (n - cnt))
