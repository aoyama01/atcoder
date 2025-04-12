# https://atcoder.jp/contests/abc351/tasks

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

n = int(input())  # 数値入力を受け取る
a = list(map(int, input().split()))  # 整数列を受け取る

q = []

for i in range(n):
    q.append(2 ** a[i])
    mouikkai = True
    while mouikkai:
        mouikkai = False
        if len(q) <= 1:
            continue
        if q[-1] != q[-2]:
            continue
        else:
            tmp = q[-1] + q[-2]
            q.pop()
            q.pop()
            q.append(tmp)
            mouikkai = True

print(len(q))
