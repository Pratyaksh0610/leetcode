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
    void fun(TreeNode*root){
        if(!root){
            return ;
        }
        if(root->left){
            TreeNode*temp=root->left;
            while(temp->right){
                temp=temp->right;
            }
            temp->right=root->right;
            root->right=root->left;
            fun(root->left);
            root->left=NULL;

        }
        else{
            fun(root->right);
        }

    }
public:
    void flatten(TreeNode* root) {
        //morris traversal use hoga
        fun(root);
        // return root;
    }
};