/*
Problem Name: Top K Frequent Elements
Problem Algorithm: Generic
Problem URL: https://leetcode.com/problems/top-k-frequent-elements/
*/

class Solution {
public:
    static bool compare(pair<int, int> p1, pair<int, int> p2) {
        return p1.second > p2.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int n : nums) {
            freq[n]++;
        }
        vector<pair<int, int>> f(freq.begin(), freq.end());
        sort(f.begin(), f.end(), compare);
        vector<int> res;
        for (int i = 0; i < k; i++) {
            res.push_back(f[i].first);
        }
        return res;
    }
};