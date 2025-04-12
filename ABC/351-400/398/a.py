# https://atcoder.jp/contests/abc398/tasks

import sys  # noqa

import numpy as np  # noqa

n = int(input())

ans = "-" * n

if n % 2 == 0:
    ans = ans[: n // 2 - 1] + "=" + ans[n // 2 :]
    ans = ans[: n // 2] + "=" + ans[n // 2 + 1 :]
else:
    ans = ans[: n // 2] + "=" + ans[n // 2 + 1 :]

print(ans)
