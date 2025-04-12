n = int(input())
a = list(map(int, input().split()))

# 値ごとの出現回数を記録
count = dict()
for i in range(n):
    if a[i] in count:
        count[a[i]] += 1
    else:
        count[a[i]] = 1
# ↓ これでもOK
# from collections import Counter  # noqa
# count = Counter(a)

max_val = 0
ans = -1

for i in range(n):
    if count[a[i]] == 1:  # 自分と同じ数が他にない
        if a[i] > max_val:
            max_val = a[i]
            ans = i + 1  # インデックスは1始まり

print(ans)
