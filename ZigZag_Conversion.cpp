/*
Problem Name: ZigZag Conversion
Problem Algorithm: Generic
Problem URL: https://leetcode.com/problems/zigzag-conversion/
*/

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        int period = 2 * numRows - 2;
        string fs;
        //first row
        for (int p = 0; p < s.length(); p += period) {
            fs.push_back(s[p]);
        }
        //middle rows
        for (int r = 1; r < numRows - 1; r++) {
            for (int p = 0; r + p < s.length(); p += period) {
                //outer period
                fs.push_back(s[r + p]);
                //inner period
                int inner_index = r + p + (numRows - 1 - r) * 2;
                if (inner_index < s.length()) {
                    fs.push_back(s[inner_index]);
                }
            }
        }
        //last row
        for (int p = numRows - 1; p < s.length(); p += period) {
            fs.push_back(s[p]);
        }
        return fs;
    }
};