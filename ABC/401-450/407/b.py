x, y = map(int, input().split())

cnt = 0
for i in range(1, 7):
    for j in range(1, 7):
        1
        if i + j >= x:
            cnt += 1
            continue
        if abs(i - j) >= y:
            cnt += 1
            continue

ans = cnt / 36
print(ans)

# 参考: https://algo-method.com/tasks/731/editorial
