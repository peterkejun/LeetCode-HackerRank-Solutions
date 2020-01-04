/*
Problem Name: Jump Game III
Problem Algorithm: Graph Theory
Problem URL: https://leetcode.com/problems/jump-game-iii/
*/

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<int> adj[arr.size()];
        int zero_index = -1;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 0) zero_index = i;
            if (i + arr[i] < arr.size()) {
                adj[i].push_back(i + arr[i]);
            }
            if (i - arr[i] >= 0) {
                adj[i].push_back(i - arr[i]);
            }
        }
        if (zero_index == -1) return false;
        //BFS
        vector<bool> visited(arr.size(), false);
        list<int> queue;
        visited[start] = true;
        queue.push_back(start);
        vector<int>::iterator i;
        while (!queue.empty()) {
            start = queue.front();
            queue.pop_front();
            for (i = adj[start].begin(); i != adj[start].end(); i++) {
                if (arr[*i] == 0) return true;
                if (!visited[*i]) {
                    visited[*i] = true;
                    queue.push_back(*i);
                }
            }
        }
        return false;
    }
};