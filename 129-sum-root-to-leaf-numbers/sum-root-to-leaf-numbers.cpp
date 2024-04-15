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
    int fun(TreeNode*root,int num){
        if(root==NULL){
            return num;
        }
        num*=10;
        num+=root->val;

        int ret=0;
        if(root->left==NULL&&root->right==NULL){
            return num;
        }
        if(root->left){
            ret+=fun(root->left,num);
        }
        if(root->right){
            ret+=fun(root->right,num);
        }
        return ret;
    }
public:
    int sumNumbers(TreeNode* root) {
        int ans=fun(root,0);
        return ans;
    }
};