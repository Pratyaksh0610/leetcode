/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
private:
    // TreeNode*alpha=NULL;
    // TreeNode*copy(TreeNode*parent){
    //     if(parent==NULL){
    //         return NULL;
    //     }
    //     TreeNode*root=new TreeNode();
    //     root->left=copy(parent->left);
    //     root->right=copy(parent->right);
    //     return root;
    // }
    vector<TreeNode*> fun(int n,vector<vector<TreeNode*>>&dp) {
        vector<TreeNode*> v;
        if(dp[n].size()!=0){
            return dp[n];
        }
        else if (n == 1) {
            TreeNode* temp = new TreeNode();
            v.push_back(temp);
            return dp[n]= v;
        }
        n--;
        for (int i = 1; i < n; i++) {
            if (i % 2 == 0) {
                continue;
            }
            vector<TreeNode*>l=fun(i,dp);
            vector<TreeNode*>r=fun(n-i,dp);
            for(int j=0;j<l.size();j++){
                for(int k=0;k<r.size();k++){
                    TreeNode* temp = new TreeNode();
                    temp->left=l[j];
                    temp->right=r[k];
                    v.push_back(temp);
                }
            }
        }
        return dp[n]= v;
    }

public:
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> ans;
        vector<vector<TreeNode*>>dp(n+1);
        if (n % 2 == 0) {
            return ans;
        }
        return fun(n,dp);
        // return ans;
    }
};