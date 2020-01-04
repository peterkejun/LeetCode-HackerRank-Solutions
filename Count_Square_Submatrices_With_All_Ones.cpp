/*
Problem Name: Count Square Submatrices with All Ones
Problem Algorithm: Dynamic Programming
Problem URL: https://leetcode.com/problems/count-square-submatrices-with-all-ones/
*/

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int num_rows = matrix.size(), num_cols = matrix[0].size();
        int table[num_rows][num_cols];
        int sum = 0;
        for (int r = 0; r < num_rows; r++) {
            for (int c = 0; c < num_cols; c++) {
                if (matrix[r][c] == 0) {
                    table[r][c] = 0;
                } else if (r == 0 || c == 0) {
                    table[r][c] = matrix[r][c];
                } else {
                    table[r][c] = min(min(table[r][c - 1], table[r - 1][c]), table[r - 1][c - 1]) + 1;
                }
                sum += table[r][c];
            }
        }
        return sum;
    }
};