# import sys  # noqa
# from collections import Counter  # noqa

# import numpy as np  # noqa
# import scipy as sp  # noqa

n = int(input())  # 数値入力を受け取る
m, l = map(int, input().split())  # 複数の数値入力を受け取る  # noqa: E741
s, t = input().split()  # 文字列を受け取る
a = list(map(int, input().split()))  # 整数列を受け取る
A = [
    list(map(int, input().split())) for _ in range(n)
]  # 複数行の整数列(2次元配列)を受け取る

print(1, end=" ")  # 改行なしの出力
print(2)  # これは改行あり
