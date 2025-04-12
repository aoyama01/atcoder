# import sys  # noqa
# from collections import Counter  # noqa

# import numpy as np  # noqa
# import scipy as sp  # noqa

n, y = map(int, input().split())  # 複数の数値入力を受け取る  # noqa: E741

found = 0
for i in range(n + 1):
    for j in range(n - i + 1):
        k = n - i - j
        if 10000 * i + 5000 * j + 1000 * k == y:
            print(i, j, k)
            found = 1
            break
    if found == 1:
        break
if found == 0:
    print(-1, -1, -1)

# nが固定されてるので，mod使いづらい(使えない？)
