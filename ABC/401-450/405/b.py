n, m = map(int, input().split())
int_list = list(map(int, input().split()))  # 整数列を受け取る

query_cnt = 0
is_all_included = True

while is_all_included:
    if query_cnt > n:
        break
    for i in range(m):
        num = i + 1
        if num not in int_list:
            is_all_included = False
    if is_all_included:
        int_list.pop()
        query_cnt += 1

print(query_cnt)
