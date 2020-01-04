/*
Problem Name: Generate Parentheses
Problem Algorithm: Backtracking
Problem URL: https://leetcode.com/problems/generate-parentheses/
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string res;
        explore(0, 0, n, res, result);
        return result;
    }
    void explore(int num_open, int num_close, int n, string& res, vector<string>& result) {
        if (res.length() == n * 2) {
            result.push_back(res);
            return;
        }
        if (num_open < n) {
            res += '(';
            explore(num_open + 1, num_close, n, res, result);
            res.pop_back();
        }
        if (num_close < num_open) {
            res += ')';
            explore(num_open, num_close + 1, n, res, result);
            res.pop_back();
        }
    }
};