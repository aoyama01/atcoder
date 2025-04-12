import numpy as np
import sys

n, c = map(int, input().split()) # 整数を受け取る
t = list(map(int, input().split())) # 整数列を受け取る

count = 1
candyGet = t[0]
for i in range(n-1):
    if(t[i+1]-candyGet >= c):
        count += 1
        candyGet = t[i+1]

print(count)
