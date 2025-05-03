import sys  # noqa
from collections import Counter, defaultdict, deque  # noqa
from copy import deepcopy  # noqa
from itertools import accumulate, combinations, permutations, product  # noqa
from math import gcd  # noqa
from operator import itemgetter  # noqa

# https://qiita.com/Kentaro_okumura/items/5b95b767a2e691cd5482

# import numpy as np  # noqa
# import scipy as sp  # noqa

sys.setrecursionlimit(10**6)  # 再帰呼び出しの上限を引き上げる

# サイクルグラフの同値

# 辺がちょうどN本(頂点と辺の個数が等しい)
# それぞれの頂点は辺をちょうど2つ持つ
# 全ての頂点を探索できる(連結)
# サイクルの個数が1つ ← これいる？

n, m = map(int, input().split())

# 辺がちょうどN本(頂点と辺の個数が等しい)かどうか
if n != m:
    print("No")
    exit()

# 頂点数mがおかしい場合も一応弾いとく
if m < 3:
    print("No")
    exit()

# グラフ入力受取（隣接リスト）
G = [[] for _ in range(n)]
for _ in range(m):
    from_node, to_node = map(int, input().split())
    # 頂点を 0-indexed に変換
    from_node -= 1
    to_node -= 1
    # 辺を (行き先, 重み) のタプルで表現する
    # 重みが不要ならタプルにせず行き先だけ
    G[from_node].append(to_node)  # 有向辺なら片方向のみ
    G[to_node].append(from_node)  # 無向辺ならこれも追加

# それぞれの頂点は辺をちょうど2つ持つかどうか
for i in range(n):
    if len(G[i]) != 2:
        print("No")
        exit()


# 深さ優先探索(DFS)
def dfs(G, v, visited):
    visited[v] = True  # 頂点 v を訪問済にする
    for to in G[v]:
        if not visited[to]:
            dfs(G, to, visited)


# 訪問フラグの初期化と DFS の実行
visited = [False] * n
dfs(G, 0, visited)  # 頂点 0 から探索開始

# 全ての頂点を探索できる(連結)かどうか
if all(visited):
    print("Yes")
else:
    print("No")
