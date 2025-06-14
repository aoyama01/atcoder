monster_num, takahashi_hp, takahashi_mp = map(int, input().split())

cnt = 0
cost_hp, cost_mp = [], []
for _ in range(monster_num):
    hp, mp = map(int, input().split())
    cost_hp.append(hp)
    cost_mp.append(mp)

# dp[i][m]: i 体目のモンスターまで倒した時点で魔力が m であるときの体力の最大値
dp = [[-1] * (takahashi_mp + 1) for _ in range(monster_num + 1)]
# 初期状態: 0体倒した時点では、魔力は takahashi_mp、体力は takahashi_hp
dp[0][takahashi_mp] = takahashi_hp

for i in range(monster_num):
    for m in range(takahashi_mp + 1):
        # そもそも i-1 体目を倒した時点で魔力 m という状態が存在しないならスキップ
        if dp[i][m] == -1:
            continue

        current_hp = dp[i][m]

        # 魔法を使わずに戦う場合
        if current_hp >= cost_hp[i]:
            new_hp = current_hp - cost_hp[i]
            dp[i + 1][m] = max(dp[i + 1][m], new_hp)

        # 魔法を使って戦う場合
        if m >= cost_mp[i]:
            new_mp = m - cost_mp[i]
            dp[i + 1][new_mp] = max(dp[i + 1][new_mp], dp[i][m])

# 答えを見つける
for i in range(monster_num, -1, -1):
    # dp[i] の中に有効な状態 (0以上の体力) があるか調べる
    if any(hp != -1 for hp in dp[i]):
        print(i)
        exit()
