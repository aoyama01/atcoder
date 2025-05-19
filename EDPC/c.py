vacation_day_num = int(input())

happiness_by_swimming = []
happiness_by_insect = []
happiness_by_homework = []

for i in range(vacation_day_num):
    a, b, c = map(int, input().split())
    happiness_by_swimming.append(a)
    happiness_by_insect.append(b)
    happiness_by_homework.append(c)

# 最初の i 日間での最適解
dp = [[0] * 3 for _ in range(vacation_day_num + 1)]

for i in range(vacation_day_num):
    for j in range(3):
        for k in range(3):
            if j == k:
                continue
            if k == 0:
                dp[i + 1][k] = max(dp[i + 1][k], dp[i][j] + happiness_by_swimming[i])
            if k == 1:
                dp[i + 1][k] = max(dp[i + 1][k], dp[i][j] + happiness_by_insect[i])
            if k == 2:
                dp[i + 1][k] = max(dp[i + 1][k], dp[i][j] + happiness_by_homework[i])


ans = max(dp[vacation_day_num])
print(ans)
