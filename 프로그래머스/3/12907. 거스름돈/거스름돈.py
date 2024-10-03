def solution(n, money):
    answer = 0
    mod = 1000000007
    
    dp = [0] * (n + 1)
    dp[0] = 1
    for m in money:
        for k in range(m, n+1):
            dp[k] += dp[k-m]

    answer = dp[n] % mod
    
    return answer