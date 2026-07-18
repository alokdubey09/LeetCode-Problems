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
       TreeNode* bfsToMapParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>&mpp, int start){
         queue<TreeNode*> q;
         q.push(root);
         TreeNode* res = new TreeNode(-1);

         while(!q.empty()){
        TreeNode* node = q.front();
         q.pop();

         if(node->val==start) res = node;
         if(node->left!=nullptr){
            mpp[node->left]=node;
            q.push(node->left);
         } if(node->right!=nullptr){
            mpp[node->right]=node;
            q.push(node->right);
         }
         }
         return res;
       }
    int findMaxDist(unordered_map<TreeNode*, TreeNode*>& mpp, TreeNode* target){
        queue<TreeNode*> q;
        q.push(target);

        unordered_map<TreeNode*, int> visited;
        visited[target]=1;
        int maxi =0;

        while(!q.empty()){
            int size=q.size();
            int f1=0;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(node->left!=nullptr && visited.find(node->left)==visited.end()){
                    f1=1;
                    visited[node->left]=1;
                    q.push(node->left);
                }
                if(node->right!=nullptr && visited.find(node->right)==visited.end()){
                    f1=1;
                    visited[node->right]=1;
                    q.push(node->right);
                }
                if(mpp.find(node)!=mpp.end() && visited.find(mpp[node])==visited.end()){
                    f1=1;
                    visited[mpp[node]] =1;
                    q.push(mpp[node]);
                }
            }
            if(f1==1) maxi++;
        }
        return maxi;
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*, TreeNode*> mpp;
            TreeNode* target = bfsToMapParents(root, mpp, start);
            int maxi = findMaxDist(mpp,target);

            return maxi;
    }
};