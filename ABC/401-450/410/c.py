import sys

sys.setrecursionlimit(10**6)

n, q = map(int, input().split())

# a = [i for i in range(n + 1)]
a = [i + 1 for i in range(n)]
offset = 0  # 回転オフセット

for i in range(q):
    type, *query = input().split()

    if type == "1":
        p, x = map(int, query)
        idx = (offset + p - 1) % n
        a[idx] = x  # Convert to 0-indexed
    elif type == "2":
        p = int(query[0])
        idx = (offset + p - 1) % n
        print(a[idx])  # Convert to 0-indexed
    elif type == "3":
        k = int(query[0])
        offset = (offset + k) % n
        # これは O(n) でボトルネックになる
        # repeat_num = k % n
        # a = a[repeat_num:] + a[:repeat_num]
