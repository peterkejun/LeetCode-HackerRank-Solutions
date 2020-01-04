/*
Problem Name: Coin Change
Problem Algorithm: Dynamic Programming
Problem URL: https://leetcode.com/problems/coin-change/
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> counts(amount + 1, amount + 1);
        counts[0] = 0;
        for (auto x : coins) {
            for(int i = x; i <= amount; i++) {
                counts[i] = min(counts[i], counts[i - x] + 1);
            }
        }
        return counts[amount] > amount ? -1 : counts[amount];
    }
};