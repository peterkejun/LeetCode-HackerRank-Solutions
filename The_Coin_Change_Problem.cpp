/*
Problem Name: The Coin Change Problem
Problem Algorithm: Dynamic Programming
Problem URL: https://www.hackerrank.com/challenges/coin-change/problem
*/

long getWays(int amount, vector<long> coins) {
    vector<long> dp(amount + 1, 0);
    dp[0] = 1;
    for (auto c : coins) {
        for (int i = c; i <= amount; i++) {
            dp[i] += dp[i - c];
        }
    }
    return dp[amount];
}