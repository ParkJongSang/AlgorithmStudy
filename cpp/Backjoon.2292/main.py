N = int(input())
range = 1
tmp = 0
ans = 0
count = 1

while True :
    if range >= N :
        ans = count
        break
    
    tmp = 6 * count
    count += 1
    range += tmp


print(ans)