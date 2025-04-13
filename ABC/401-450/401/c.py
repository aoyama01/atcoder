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

n, k = map(int, input().split())  # 複数の数値入力を受け取る  # noqa: E741

MOD = 10**9

if n < k:
    print(1)
    sys.exit()

a = [0] * (n + 1)
cum_sum = [0] * (n + 2)  # 累積和配列

# 初期化
for i in range(k):
    a[i] = 1
    cum_sum[i + 1] = cum_sum[i] + a[i]

for i in range(k, n + 1):
    a[i] = (cum_sum[i] - cum_sum[i - k]) % MOD
    cum_sum[i + 1] = (cum_sum[i] + a[i]) % MOD


print(a[n])
