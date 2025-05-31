# https://imoz.jp/algorithms/imos_method.html
n, m = map(int, input().split())

diff = [0] * (n + 2)  # 1-indexed

for _ in range(m):
    l, r = map(int, input().split())
    diff[l] += 1
    diff[r + 1] -= 1

ans = m  # 最大でも m 本
cur = 0
for i in range(1, n + 1):
    cur += diff[i]
    ans = min(ans, cur)

print(ans)
