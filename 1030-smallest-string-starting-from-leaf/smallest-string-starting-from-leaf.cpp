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
    string ans="";
    void fun(TreeNode* root,string temp){
        int val=root->val;
        temp.push_back('a'+val);
        if(root->left==NULL&&root->right==NULL){
            reverse(temp.begin(),temp.end());
            if(ans.size()==0){
                ans=temp;
            }
            int val=temp.compare(ans);
            if(val<0){
                ans=temp;
            }
            return;
        }
        if(root->left){
            fun(root->left,temp);
        }
        if(root->right){
            fun(root->right,temp);
        }
    }
public:
    string smallestFromLeaf(TreeNode* root) {
        fun(root,"");
        return ans;
    }
};