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

n, m = map(int, input().split())

dishes = []
element_to_dishes = defaultdict(set)  # 要素xが含まれるdishのインデックス集合

for i in range(m):
    values = list(map(int, input().split()))
    a_i = set(values[1:])
    dishes.append(a_i)
    for val in a_i:
        element_to_dishes[val].add(i)

likes = list(map(int, input().split()))

flags = [False] * m  # すでに空になったdishは二重カウントしない
cnt = 0

for b in likes:
    if b in element_to_dishes:
        for i in element_to_dishes[b]:
            dishes[i].discard(b)
            if not dishes[i] and not flags[i]:
                flags[i] = True
                cnt += 1
        # 一度処理した要素bに対応する集合はもう不要
        del element_to_dishes[b]
    print(cnt)
