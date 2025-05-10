r, x = map(int, input().split())

if x == 1:
    if 1600 <= r <= 2999:
        print("Yes")
        exit()
if x == 2:
    if 1200 <= r <= 2399:
        print("Yes")
        exit()

print("No")
