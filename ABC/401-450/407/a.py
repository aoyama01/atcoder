import math

a, b = map(int, input().split())
num = a / b

num_ceil = math.ceil(num)  # 切り上げた数
num_floor = math.floor(num)  # 切り下げた数

diff_ceil = abs(num_ceil - num)
diff_floor = abs(num - num_floor)

if diff_ceil < diff_floor:
    ans = int(num_ceil)
else:
    ans = int(num_floor)

print(ans)
