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
    int fun(TreeNode*root,int &maxi){
        if(root==NULL){
            return 0;
        }
        int a=fun(root->left,maxi);
        int b=fun(root->right,maxi);
        int m=max(a,b);
        maxi=max(maxi,a+b+1);
        return m+1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=0;
        if(root==NULL){
            return maxi;
        }
        fun(root,maxi);
        return maxi-1;
    }
};