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
m, l = map(int, input().split())  # 複数の数値入力を受け取る  # noqa: E741
s, t = input().split()  # 文字列を受け取る
a = list(map(int, input().split()))  # 整数列を受け取る
A = [
    list(map(int, input().split())) for _ in range(n)
]  # 複数行の整数列(2次元配列)を受け取る

print(1, end=" ")  # 改行なしの出力
print(2)  # これは改行あり

# "o" が連続しない という条件をあらかじめ決めておくことで，boolの欠損値を補完できる場合があるってこと？
