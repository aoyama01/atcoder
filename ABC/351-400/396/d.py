N, M = map(int, input().split())
G = [[] for _ in range(N)]  # 修正ポイント

for _ in range(M):
    u, v, w = map(int, input().split())
    u -= 1
    v -= 1
    G[u].append((v, w))
    G[v].append((u, w))

ans = 1 << 60
visited = [False] * N


def dfs(v, xor):
    global ans
    visited[v] = True
    if v == N - 1:
        ans = min(ans, xor)
    for u, w in G[v]:
        if not visited[u]:
            dfs(u, xor ^ w)
    visited[v] = False


dfs(0, 0)
print(ans)
