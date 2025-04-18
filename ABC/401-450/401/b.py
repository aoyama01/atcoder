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
# s = list(input().split())
s = [input() for _ in range(n)]

is_login = False
error_cnt = 0

for i in range(n):
    if s[i] == "login":
        is_login = True
    if s[i] == "logout":
        is_login = False
    if s[i] == "private" and not is_login:
        error_cnt += 1

print(error_cnt)
