N = int(input())
idx = 0
cur_num = 1
arr = []
cnt = 0
ans = ""

while cnt < N:
    arr.append(0)
    cnt += 1

while cur_num <= N:
    cnt = 0
    while cnt < cur_num:
        if arr[idx] == 0:
            cnt += 1;

        idx += 1
        if idx >= N:
            idx = 0

    while arr[idx] > 0:
        idx += 1
        if idx >= N:
            idx = 0

    arr[idx] = cur_num
    cur_num += 1
    
for num in arr:
    ans += str(num) + ' '

print(ans)