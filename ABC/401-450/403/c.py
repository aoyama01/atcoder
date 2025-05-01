from collections import Counter, defaultdict, deque  # noqa

n, m, q = map(int, input().split())  # 複数の数値入力を受け取る

# データ構造を考える
dict = defaultdict(set)  # ユーザーが権限を持つページ
all_allowed = set()  # 全てのページへの権限をもつユーザー

for i in range(q):
    n, *a = map(int, input().split())

    if n == 1:
        # print(f"ユーザー{a[0]}にページ{a[1]}の権限を付与")
        dict[a[0]].add(a[1])
    elif n == 2:
        # print(f"ユーザー{a[0]}に全てのページへの権限を付与")
        all_allowed.add(a[0])
    elif n == 3:
        # print(f"ユーザー{a[0]}はページ{a[1]}にアクセスできる？")
        if a[0] in all_allowed or a[1] in dict[a[0]]:
            # Xがすべてのページへの権限を持っている or Xか権限を持っているページにYが含まれているか
            print("Yes")
        else:
            print("No")

# 計算量は？ → Qじゃね？
# 使えるデータ構造もメモしときたい
