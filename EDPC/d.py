import sys


def input():
    return sys.stdin.readline()[:-1]


item_num, weight_max = map(int, input().split())

item_weights = []
item_values = []
for i in range(item_num):
    w, v = map(int, input().split())
    item_weights.append(w)
    item_values.append(v)

# dp[i][w]: i 番目までで重さが w のときの、価値の総和
dp = [[0] * (weight_max + 1) for _ in range(item_num + 1)]
for i in range(item_num):
    for w in range(weight_max + 1):
        # item を選ばないとき
        dp[i + 1][w] = max(dp[i + 1][w], dp[i][w])
        # item を選ぶとき(選べるなら)
        if w + item_weights[i] <= weight_max:
            dp[i + 1][w + item_weights[i]] = max(
                dp[i + 1][w + item_weights[i]], dp[i][w] + item_values[i]
            )

    # 「選ぶ→選ばない」の順だと、不正な値に基づいて上書きされてしまう可能性がある
    # DPでは「未来の値の更新が他の遷移に影響しない」ことが大原則
    # そのため、選択肢を複数持つ場合は「選ばない」処理を先にするのが鉄則

ans = max(dp[item_num])
print(ans)
