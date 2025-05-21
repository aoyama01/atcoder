item_num, weight_max = map(int, input().split())

item_weights = []
item_values = []
for i in range(item_num):
    w, v = map(int, input().split())
    item_weights.append(w)
    item_values.append(v)

# dp[i][sum_v]: i-1 番目までの item から価値が sum_v となるように選んだときの、重さの総和の最小値
value_sum = sum(item_values)
INF = float("inf")
dp = [[INF] * (value_sum + 1) for _ in range(item_num + 1)]
dp[0][0] = 0  # 初期条件

for i in range(item_num):
    for v in range(value_sum + 1):
        # item を選ばないとき
        dp[i + 1][v] = min(dp[i + 1][v], dp[i][v])
        # item を選ぶとき(選べるなら)
        if v + item_values[i] <= value_sum:
            dp[i + 1][v + item_values[i]] = min(
                dp[i + 1][v + item_values[i]], dp[i][v] + item_weights[i]
            )

# ans: 重さの総和が W を超えない範囲で sum_v を最大にしたときの dp[N][sum_v]
ans = 0
for v in range(value_sum + 1):
    if dp[item_num][v] <= weight_max:
        ans = v
print(ans)
