/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private: 
    void func(TreeNode* root, int targetSum, vector<int>& pathSum, vector<vector<int>>& Sums){
        if(root==nullptr) return;

        if(root->left == nullptr && root->right == nullptr){
            if(targetSum == root->val){
                pathSum.push_back(root->val);
                Sums.push_back(pathSum);
                pathSum.pop_back();
            }
            return;
        }
        pathSum.push_back(root->val);
        func(root->left, targetSum-root->val, pathSum, Sums);
        func(root->right, targetSum-root->val, pathSum, Sums);
        pathSum.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
         vector<vector<int>> Sums;
         vector<int> pathSum;
         func(root, targetSum, pathSum, Sums);
         return Sums;
    }
};