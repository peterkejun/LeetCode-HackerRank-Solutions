/*
Problem Name: Arithmetic Slices
Problem Algorithm: Dynamic Programming
Problem URL: https://leetcode.com/problems/arithmetic-slices/
*/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() <= 2) return 0;
        int dp[A.size()];   //num of arithmetic slices up to i
        dp[0] = 0;
        dp[1] = 0;
        int interval = A[1] - A[0];
        int con = 2;
        int sum = 0;
        for (int i = 2; i < A.size(); i++) {
            if (A[i] - A[i - 1] == interval) {
                con++;
                dp[i] = con - 2 + dp[i - 1];
            } else {
                interval = A[i] - A[i - 1];
                con = 2;
                dp[i] = 0;
                sum += dp[i - 1];
            }
        }
        sum += dp[A.size() - 1];
        return sum;
    }
};