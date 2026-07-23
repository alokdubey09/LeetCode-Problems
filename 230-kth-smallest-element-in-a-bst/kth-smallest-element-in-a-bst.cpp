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
      void inorderTraversal(TreeNode* node, vector<int>& ans){
        if(node){
            inorderTraversal(node->left, ans);
            ans.push_back(node->val);
            inorderTraversal(node->right, ans);
        }
      }
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ans;
        inorderTraversal(root, ans);
       int kth_smallest = ans[k-1];

        return kth_smallest;
    }
};