n = int(input())
a = list(map(int, input().split()))  # 整数列を受け取る

total = sum(a)
squared_sum = sum(x * x for x in a)

ans = (total * total - squared_sum) // 2
print(ans)


# # Nが10^4より大きければ、必ずAに重複が存在する
# # Aのリストを上下に並べる
# # 上のAの値と、下のAのインデックス(jのスタート地点)から、sumを求めれるようなメモ化をしたい
# sum = 0
# memo = {}
# for i in range(n):
#     if (a[i], i + 1) in memo:
#         sum += memo[(a[i], i + 1)]
#         break
#     memo[(a[i], i + 1)] = 0
#     for j in range(i + 1, n):
#         sum += a[i] * a[j]
#         memo[(a[i], i + 1)] += a[i] * a[j]

# print(sum)
