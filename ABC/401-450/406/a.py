hour_deadline, minute_deadline, hour_submitted, minute_submitted = map(
    int, input().split()
)

if hour_submitted > hour_deadline:
    print("No")
    exit()
elif hour_submitted == hour_deadline:
    if minute_submitted > minute_deadline:
        print("No")
        exit()

print("Yes")
