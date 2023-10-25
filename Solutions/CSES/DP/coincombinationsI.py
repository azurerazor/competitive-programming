n, x = map(int, input().split(" "))
coins = list(map(int, input().split(" ")))
 
dp = [0] * (x + 1)
dp[0] = 1
 
for i in range(x + 1):
    if dp[i] == 0:
        continue
 
    for j in coins:
        if i + j <= x:
            dp[i + j] += dp[i]
            dp[i + j] %= 1000000007
 
print(dp[x])