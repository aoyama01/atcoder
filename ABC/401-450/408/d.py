def solve_one(n: int, s: str) -> int:
    total_ones = s.count("1")

    # Kadane 法（最小部分和）
    min_ending_here = 0  # 直近で終わる部分列の最小和
    min_subarray_sum = 0  # 全体の最小部分和（空列 = 0 を許す）

    for ch in s:
        val = 1 if ch == "0" else -1
        min_ending_here = min(val, min_ending_here + val)
        min_subarray_sum = min(min_subarray_sum, min_ending_here)

    return total_ones + min_subarray_sum


t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    print(solve_one(n, s))
