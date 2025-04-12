n = 7
a = list(map(int, input().split()))  # 整数列を受け取る


three_pair = -1

for i in range(n):
    two = False
    three = False
    for j in range(i + 1, n):
        if a[i] == a[j]:
            if two:
                three = True
                three_pair = a[i]
            else:
                two = True

if three_pair != -1:
    # 3ペアが存在する場合
    two = False
    for i in range(n):
        for j in range(i + 1, n):
            if a[i] != three_pair and a[i] == a[j]:
                two = True
    if two:
        print("Yes")
    else:
        print("No")
else:
    print("No")
