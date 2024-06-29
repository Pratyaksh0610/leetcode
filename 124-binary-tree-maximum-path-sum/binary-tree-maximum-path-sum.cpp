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
    int ans=INT_MIN;
    int fun(TreeNode*root){
        if(root==NULL){
            return -1e8;
        }
        int l=fun(root->left);
        int r=fun(root->right);
        ans=max(ans,root->val);
        ans=max(ans,l+r+root->val);
        ans=max(ans,l+root->val);
        ans=max(ans,r+root->val);
        int ret=max(root->val,max(l,r)+root->val);
        return ret;
    }
public:
    int maxPathSum(TreeNode* root) {
        fun(root);
        return ans;
    }
};