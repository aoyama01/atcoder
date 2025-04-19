from collections import deque

q = int(input())
que = deque()

for i in range(q):
    n = list(map(int, input().split()))
    if n[0] == 1:
        que.append(n[1])
    else:
        print(que.popleft())
