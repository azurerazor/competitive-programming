x = int(input())
ans = 0
t = 5
while t <= x:
    ans += x//t
    t *= 5
    
print(ans)
