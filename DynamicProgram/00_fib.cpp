#include<string>
#include<cassert>
#include<iostream>
#include<stdlib.h>
#include <stdio.h>
#include <string.h>

long fib(int n, long dp[]);

int main(int argc, char** argv)
{
    int val;
    std::cout<<"Type a number of fibonacci value: "<<std::endl;
    std::cin >>val;

    long dp[val];   
    memset(dp, 0, sizeof(dp));
    dp[0] = dp[1] = 1;

    long result = fib(val, dp);
    
    std::cout<<"Fibnacci value of "<<val<<" is "<<result<<std::endl;

    return 0;
}

long fib(int n, long dp[])
{
    if (n == 1 || n == 2) return dp[0];

    if (dp[n-2] == 0)
        dp[n-2] = fib(n-1, dp);

    if (dp[n-3] == 0)
        dp[n-3] = fib(n-2, dp);

    return dp[n-2] + dp[n-3];
}