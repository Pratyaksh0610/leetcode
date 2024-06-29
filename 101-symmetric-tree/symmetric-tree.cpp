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
    bool fun(TreeNode*left,TreeNode*right){
        if(!left&&!right){
            return true;
        }
        else if(!left||!right||left->val!=right->val){
            return false;
        }
        return fun(left->right,right->left)&fun(left->left,right->right);
    }
public:
    bool isSymmetric(TreeNode* root) {
        if(!root){
            return true;
        }
        return fun(root->left,root->right);
    }
};