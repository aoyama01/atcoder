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

T = int(input())
for _ in range(T):
    N = int(input())
    A = list(map(int, input().split()))

    position = defaultdict(list)
    for i in range(2 * N):
        position[A[i]].append(i)

    answers = set()
    for i in range(2 * N - 1):
        a, b = A[i], A[i + 1]
        if position[a][0] + 1 == position[a][1]:
            continue
        if position[b][0] + 1 == position[b][1]:
            continue
        v = [position[a][0], position[a][1], position[b][0], position[b][1]]
        v.sort()
        if v[0] + 1 == v[1] and v[2] + 1 == v[3]:
            answers.add(tuple(sorted((a, b))))

    print(len(answers))
