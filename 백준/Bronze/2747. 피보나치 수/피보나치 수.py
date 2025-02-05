dp = [0] * 50
def fib(num):
    if(num == 0):
        return dp[0]
    elif(dp[num] != 0):
        return dp[num]
    dp[num] = fib(num - 2) + fib(num - 1)
    return dp[num]

dp[1] = 1
n = int(input())
print(fib(n))