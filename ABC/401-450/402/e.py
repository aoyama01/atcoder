# 入力受け取り
N, X = map(int, input().split())
S = [0] * N
C = [0] * N
P = [0] * N
for i in range(N):
    S[i], C[i], P[i] = map(int, input().split())

# print(S)
# print(C)
# print(P)

# bit は 2^N 通りの部分集合全体を動く
exp_max = 0
for bit in range(1 << N):
    total_exp = 0
    total_cost = 0  # 部分集合に含まれる要素の和
    for i in range(N):
        # i 番目の要素を部分集合に含むとき
        if bit & (1 << i):
            # total_exp += S[i] * P[i] / 100
            total_exp += 1 - (1 - P[i] / 100) ** S[i]
            total_cost += C[i]

    # total が X 以内に収まる場合
    if total_cost <= X:
        exp_max = max(exp_max, total_exp)

print(exp_max)
