# 「現在入っているボールが最も少ない箱のうち番号が最小である箱」をメモしとく？

n, q = map(int, input().split())
x = list(map(int, input().split()))

a = [0] * n

log = []

for i in range(q):
    if x[i] >= 1:
        a[x[i] - 1] += 1  # x is 1-indexed
        log.append(x[i])
    else:
        min_idx = a.index(min(a))
        a[min_idx] += 1
        log.append(min_idx + 1)  # Convert to 1-indexed

for i in range(q):
    if i == q - 1:
        print(log[i])
    else:
        print(log[i], end=" ")

# 参考：https://hibiki-press.tech/python/max_min_index/586
