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
s = [input() for _ in range(n)]  # 複数行の文字列を受け取る
t = [input() for _ in range(n)]  # 複数行の文字列を受け取る

# 最初に回転させて、4通りそれぞれの場合の最小変更回数を把握する？
# てことは普通に全探索で計算量間に合う？？

# ただし、回転時にも1回カウントされることに注意

# 回転させない場合
cnt_no_rot = 0
for i in range(n):
    for j in range(n):
        if s[i][j] != t[i][j]:
            cnt_no_rot += 1

# 90度回転
cnt_one_rot = 0
for i in range(n):
    for j in range(n):
        if s[i][j] != t[j][n - 1 - i]:
            cnt_one_rot += 1
cnt_one_rot += 1

# 180度回転
cnt_two_rot = 0
for i in range(n):
    for j in range(n):
        if s[i][j] != t[n - 1 - i][n - 1 - j]:
            cnt_two_rot += 1
cnt_two_rot += 2

# 270度回転
cnt_three_rot = 0
for i in range(n):
    for j in range(n):
        if s[i][j] != t[n - 1 - j][i]:
            cnt_three_rot += 1
cnt_three_rot += 3


print(cnt_no_rot, cnt_one_rot, cnt_two_rot, cnt_three_rot)
print(min(cnt_no_rot, cnt_one_rot, cnt_two_rot, cnt_three_rot))

# 別解
# N = int(input())
# S = [input() for _ in range(N)]
# T = [input() for _ in range(N)]

# def right_rot90(S):
#   return list(zip(*S[::-1]))

# def count_diff(S,T):
#   return sum([1 for si,ti in zip(S,T) for sij,tij in zip(si,ti) if sij!=tij])

# ans = 10**9
# for rot_count in range(4):
#   ans = min(ans, count_diff(S,T)+rot_count)
#   S = right_rot90(S)

# print(ans)
