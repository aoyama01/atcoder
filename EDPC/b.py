foothold_num, step_length = map(int, input().split())
foothold_heifghts = list(map(int, input().split()))

# DPテーブルと初期条件
INF = float("inf")
dp = [INF] * (foothold_num + 1)
dp[0] = 0

# # 配る(push-based)DP
# for i in range(foothold_num):
#     for k in range(1, step_length + 1):
#         if i + k < foothold_num:
#             dp[i + k] = min(
#                 dp[i + k], dp[i] + abs(foothold_heifghts[i + k] - foothold_heifghts[i])
#             )


# # 貰う(pull-based)DP
for i in range(1, foothold_num):
    for k in range(1, step_length + 1):
        if i >= k:
            dp[i] = min(
                dp[i], dp[i - k] + abs(foothold_heifghts[i] - foothold_heifghts[i - k])
            )

ans = dp[foothold_num - 1]
print(ans)

# インデックスにまじで注意！
