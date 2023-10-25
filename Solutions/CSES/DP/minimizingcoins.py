inf = 1e9

n, x = map(int, input().split(" "))
coins = list(map(int, input().split(" ")))
dp = [inf] * (x+1)
dp[0] = 0

for i in range(x+1):
    if dp[i] == inf:
        continue

    for j in coins:
        if i+j <= x:
            dp[i+j] = min(dp[i+j], dp[i]+1)

if dp[x] == inf:
    print(-1)
else:
    print(dp[x])
