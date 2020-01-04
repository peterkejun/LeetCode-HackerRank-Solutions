/*
Problem Name: Permutations
Problem Algorithm: Backtracking
Problem URL: https://leetcode.com/problems/permutations/
*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> res;
        explore(nums, result, res);
        return result;
    }
    void explore(vector<int>& nums, vector<vector<int>>& result, vector<int>& res) {
        if (nums.size() == 0) {
            result.push_back(res);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            int chosen = nums[i];
            res.push_back(chosen);
            nums.erase(nums.begin() + i);
            explore(nums, result, res);
            res.pop_back();
            nums.insert(nums.begin() + i, chosen);
        }
    }
};