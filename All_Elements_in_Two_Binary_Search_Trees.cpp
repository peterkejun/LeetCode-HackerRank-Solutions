/*
Problem Name: All Elements in Two Binary Search Trees
Problem Algorithm: Greedy (Optimal Merge Pattern)
Problem URL: https://leetcode.com/problems/all-elements-in-two-binary-search-trees/
*/


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    void getElements(TreeNode *node, vector<int>& arr) {
        if (node == NULL) return;
        getElements(node->left, arr);
        arr.push_back(node->val);
        getElements(node->right, arr);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> arr1, arr2;
        getElements(root1, arr1);
        getElements(root2, arr2);
        vector<int> arr(arr1.size() + arr2.size());
        int i = 0, j = 0, k = 0;
        while (i < arr1.size() && j < arr2.size()) {
            if (arr1[i] < arr2[j]) arr[k++] = arr1[i++];
            else arr[k++] = arr2[j++];
        }
        while (i < arr1.size()) arr[k++] = arr1[i++];
        while (j < arr2.size()) arr[k++] = arr2[j++];
        return arr;
    }
};