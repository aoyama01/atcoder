from collections import deque

s = deque(input())

# 方針
# 操作終了時の状態(入力値)から復元していく
# 一の位の数 a を取り出す
# 過去に、最小で a + 1 回ボタンを押したことが自明
cnt_buttonA = 0
cnt_buttonB = 0
MOD = 10  # たぶん 9 か 10
while s:
    ones_place = int(s.pop())
    # 各桁の数字が1増えるのはボタンBでのみ
    ones_place = (ones_place - (cnt_buttonB)) % MOD
    # 直前に、ボタンBを cnt_buttonB 回、ボタンAを1回押していた
    cnt_buttonB += ones_place
    cnt_buttonA += 1

ans = cnt_buttonA + cnt_buttonB
print(ans)
