N = int(input())

cache = [[0 for x in range(2)] for y in range(100001)]

cache[1][0] = 1;
cache[1][1] = 2;

for i in range(2, 100001):
    cache[i][0] = (cache[i-1][0] + cache[i-1][1]) % 9901
    cache[i][1] = (2*cache[i-1][0] + cache[i-1][1]) % 9901

print((cache[N][0]+cache[N][1])%9901)