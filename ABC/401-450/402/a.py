# https://atcoder.jp/contests/abc402/tasks

s = input()
ans = ""

for i in range(len(s)):
    if s[i].isupper():
        ans += s[i]

print(ans)

# 別解
s = input()
ans = ""
for c in s:
    if ord("A") <= ord(c) and ord(c) <= ord("Z"):
        ans += c
print(ans)
