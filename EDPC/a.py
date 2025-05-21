# https://qiita.com/drken/items/dc53c683d6de8aeacf5a

foothold_num = int(input())
foothold_heifghts = list(map(int, input().split()))

# DPテーブルと初期条件
INF = float("inf")
dp = [INF] * (foothold_num + 1)
dp[0] = 0

# 配る(push-based)DP
# for i in range(foothold_num):
#     if i + 1 < foothold_num:
#         dp[i + 1] = min(
#             dp[i + 1], dp[i] + abs(foothold_heifghts[i + 1] - foothold_heifghts[i])
#         )
#     if i + 2 < foothold_num:
#         dp[i + 2] = min(
#             dp[i + 2], dp[i] + abs(foothold_heifghts[i + 2] - foothold_heifghts[i])
#         )

# 貰う(pull-based)DP
for i in range(1, foothold_num):
    dp[i] = min(dp[i], dp[i - 1] + abs(foothold_heifghts[i] - foothold_heifghts[i - 1]))
    if i > 1:
        dp[i] = min(
            dp[i], dp[i - 2] + abs(foothold_heifghts[i] - foothold_heifghts[i - 2])
        )

ans = dp[foothold_num - 1]
print(ans)

# インデックスに注意！
