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
    
    struct Node {
    int maxNode, minNode, Sum;
    Node(int minNode, int maxNode, int Sum){
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->Sum = Sum;
    }
 };

public:

    int ans = 0;
        Node Helper(TreeNode* root){
            if(!root) return Node(INT_MAX,INT_MIN, 0);
            Node left = Helper(root->left);
            Node right = Helper(root->right);

            if(left.maxNode<root->val && right.minNode>root->val){
                int currSum = left.Sum + right.Sum + root->val;
                ans = max(ans, currSum);

                return Node(min(root->val, left.minNode), max(root->val, right.maxNode), currSum);
            }
            return Node(INT_MIN, INT_MAX,0);
        }

    int maxSumBST(TreeNode* root) {
        Helper(root);
        return ans;
    }
};