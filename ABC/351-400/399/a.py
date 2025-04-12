# https://atcoder.jp/contests/abc399/tasks

# import sys  # noqa
# from collections import Counter  # noqa

# import numpy as np  # noqa
# import scipy as sp  # noqa

n = int(input())
s = input()
t = input()

count = 0

for i in range(n):
    if s[i] != t[i]:
        count += 1

print(count)
