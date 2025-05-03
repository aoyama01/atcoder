# https://atcoder.jp/contests/abc404/tasks

s = input()

code = ord("a")
while True:
    ch = chr(code)
    isInclude = False
    for i in range(len(s)):
        if s[i] == ch:
            isInclude = True
    if not isInclude:
        print(ch)
        exit()
    code += 1
