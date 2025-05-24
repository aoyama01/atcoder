s = input()
t = input()

length_max = 3010

dp = [[0] * length_max for _ in range(length_max)]

# DPループ
for i in range(len(s)):
    for j in range(len(t)):
        1
        if s[i] == t[j]:
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1)
        dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i + 1][j])
        dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j + 1])

# 復元
ans = ""
i = len(s)
j = len(t)
while i > 0 and j > 0:
    # (i-1, j) -> (i, j) と更新されていた場合
    if dp[i][j] == dp[i - 1][j]:
        i -= 1  # DP の遷移を遡る

    # (i, j-1) -> (i, j) と更新されていた場合
    elif dp[i][j] == dp[i][j - 1]:
        j -= 1

    # (i-1, j-1) -> (i, j) と更新されていた場合
    else:
        ans = s[i - 1] + ans
        i -= 1
        j -= 1

print(ans)
