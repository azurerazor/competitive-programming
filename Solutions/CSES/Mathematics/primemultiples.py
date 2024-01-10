n, k = map(int, input().split())
primes = list(map(int, input().split()))
ans = 0
for i in range(1, (1 << k)):
    prod = 1
    popcnt = 0
    for j in range(k):
        if (i & (1 << j)) > 0:
            prod *= primes[j]
            popcnt += 1
        if prod > n:
            break
    if popcnt % 2 == 1:
        ans += n//prod
    else:
        ans -= n//prod
print(ans)