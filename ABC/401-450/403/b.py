t = input()
u = input()

# t を idx_range = len(t) - len(u) + 1 まで走査
idx_range = len(t) - len(u) + 1

isIncluded = False
for i in range(idx_range):
    isSame = True
    for j in range(len(u)):
        if t[i + j] != u[j] and t[i + j] != "?":
            isSame = False
    if isSame:
        isIncluded = True

if isIncluded:
    print("Yes")
else:
    print("No")
