num_query, max_digit = map(int, input().split())
queries = list(map(int, input().split()))

ans = 1
max_value = 10**max_digit - 1
for i in range(num_query):
    ans *= queries[i]
    if ans > max_value:
        ans = 1

print(ans)
