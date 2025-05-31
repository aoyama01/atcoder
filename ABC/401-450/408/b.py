n = int(input())
a = list(map(int, input().split()))

s = set(a)
a = list(s)
a.sort()

m = len(a)
print(m)
for i in range(m):
    if i == m - 1:
        print(a[i])
    else:
        print(a[i], end=" ")
