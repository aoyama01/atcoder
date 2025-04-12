# import sys  # noqa
# from collections import Counter  # noqa

# import numpy as np  # noqa
# import scipy as sp  # noqa


n = int(input())  # 数値入力を受け取る
# t, a = map(int, input().split())  # 複数の数値入力を受け取る  # noqa: E741

takahashi_min = 1
aoki_min = 1

for i in range(n):
    t, a = map(int, input().split())  # 複数の数値入力を受け取る  # noqa: E741

    k = max(takahashi_min // t, aoki_min // a)
    while t * k < takahashi_min or a * k < aoki_min:
        k += 1
    # t * k >= takahashi_min and a * k >= aoki_min のとき
    takahashi_min = t * k
    aoki_min = a * k

print(takahashi_min + aoki_min)
