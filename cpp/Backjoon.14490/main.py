def gcd(a, b):
    if b == 0 :
        return a
    return gcd(b, a%b)

str = input()
num_list = str.split(':')
org_N = int(num_list[0])
org_M = int(num_list[1])
N = int(num_list[0])
M = int(num_list[1])

if N < M:
    tmp = N
    N = M
    M = tmp

div = gcd(N, M)

result = "%d:%d" %(org_N/div, org_M/div)

print(result)
