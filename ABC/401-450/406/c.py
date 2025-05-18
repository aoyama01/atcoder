# def is_tilde(sequence):
#     if len(sequence) < 4:
#         return False
#     if sequence[0] >= sequence[1]:
#         return False
#     cnt_peak = 0
#     cnt_valley = 0
#     for i in range(1, len(sequence) - 1):
#         if sequence[i - 1] < sequence[i] and sequence[i] > sequence[i + 1]:
#             cnt_peak += 1
#             if cnt_peak > 1:
#                 return False
#         elif sequence[i - 1] > sequence[i] and sequence[i] < sequence[i + 1]:
#             cnt_valley += 1
#             if cnt_valley > 1:
#                 return False
#     return True

# 参考
# https://qiita.com/drken/items/a207e5ae3ea2cf17f4bd
# https://qiita.com/maebaru/items/c30a9abbb5989340763e

sequence_length = int(input())
sequence = list(map(int, input().split()))

is_peak = [0] * sequence_length
is_valley = [0] * sequence_length
for i in range(1, sequence_length - 1):
    if sequence[i - 1] < sequence[i] > sequence[i + 1]:
        is_peak[i] = 1
    elif sequence[i - 1] > sequence[i] < sequence[i + 1]:
        is_valley[i] = 1

peak_sum = [0] * (sequence_length + 1)
valley_sum = [0] * (sequence_length + 1)
for i in range(sequence_length):
    peak_sum[i + 1] = peak_sum[i] + is_peak[i]
    valley_sum[i + 1] = valley_sum[i] + is_valley[i]

cnt = 0

for left in range(sequence_length - 3):
    # 条件 2 のチェック
    if sequence[left] >= sequence[left + 1]:
        continue

    for right in range(left + 3, sequence_length):
        num_peaks = peak_sum[right] - peak_sum[left + 1]
        num_valleys = valley_sum[right] - valley_sum[left + 1]
        if num_peaks == 1 and num_valleys == 1:
            cnt += 1
        # 条件 3, 4 のチェック
        elif num_peaks > 1 or num_valleys > 1:
            break  # これ以上長い部分数列も条件を満たさない

print(cnt)
