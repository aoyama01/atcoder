vacation_day_num = int(input())

# happiness[i][k] = i日目に行動k(0:水泳, 1:虫取り, 2:宿題)をしたときの幸福度
happiness = []
for _ in range(vacation_day_num):
    a, b, c = map(int, input().split())
    happiness.append([a, b, c])

# dp[i][j] = i日目までで、前日に行動jをしたときの最大幸福度
dp = [[0] * 3 for _ in range(vacation_day_num + 1)]

for i in range(vacation_day_num):
    for j in range(3):  # 前日の行動
        for k in range(3):  # 今日の行動
            if j == k:
                continue
            dp[i + 1][k] = max(dp[i + 1][k], dp[i][j] + happiness[i][k])

ans = max(dp[vacation_day_num])
print(ans)
