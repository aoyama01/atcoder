import numpy as np
import sys

n, m, l = map(int, input().split()) # 整数を受け取る
s, t = input().split() # 文字列を受け取る
a = list(map(int, input().split())) # 整数列を受け取る
A = [list(map(int, input().split())) for _ in range(n)] # 複数行の整数列(2次元配列)を受け取る

print(1, end=' ') # 改行なしの出力
print(2) # これは改行あり
