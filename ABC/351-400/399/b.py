# import sys  # noqa
# from collections import Counter  # noqa

import numpy as np  # noqa

# import scipy as sp  # noqa

n = int(input())
p = list(map(int, input().split()))  # 整数列を受け取る
rank = [0] * n
r = 0

# print(max(p))
# print(np.argmax(p))

max_val = 101
# max_val = max(p)
cnt = 0
for _ in range(n):
    max_ind = np.argmax(p)
    if max_val != p[max_ind]:
        max_val = p[max_ind]
        # r += 1
        # r += cnt
        r = r + 1 + cnt
        cnt = 0
    else:
        cnt += 1
    rank[max_ind] = r
    p[max_ind] = -1


for i in range(n):
    print(rank[i])

# 別解
# n = int(input())
# p = list(map(int, input().split()))
# for i in range(n):
#   rank = 1
#   for j in range(n):
#     if p[j] > p[i]:
#       rank += 1
#   print(rank)
