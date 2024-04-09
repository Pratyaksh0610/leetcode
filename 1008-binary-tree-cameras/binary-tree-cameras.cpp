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
    int fun(TreeNode* root, unordered_map<TreeNode*, int>& m,
            unordered_map<TreeNode*, int>& m2,unordered_map<TreeNode*,int>&m3, int comp) {
        if (root->left == NULL && root->right == NULL) {
            if(comp==-1){
                return 0;
            }
            else if(comp==1||comp==0){
                return 1;
            }
        }
        if (comp == 1) {
            if (m2.find(root) != m2.end()) {
                return m2[root];
            }
        } else if (comp == 0) {
            if (m.find(root) != m.end()) {
                return m[root];
            }
        }
        else if(comp==-1){
            if(m3.find(root)!=m3.end()){
                return m3[root];
            }
        }

        if (comp == 1) {
            // comp
            int val = 1;
            if (root->left) {

                val += fun(root->left, m, m2,m3, -1);
            }
            if (root->right) {

                val += fun(root->right, m, m2,m3, -1);
            }
            return m2[root] = val;
        } else if(comp==0) {
            // not comp
            int take = 1, ntake = INT_MAX;
            int a=INT_MAX,b=INT_MAX,c=INT_MAX;
            if (root->left) {
                take += fun(root->left, m, m2,m3, -1);
                // ntake += fun(root->left, m, m2,m3, 1);
            }
            if (root->right) {
                take += fun(root->right, m, m2,m3, -1);
                // ntake += fun(root->right, m, m2,m3, 1);
            }
            if(root->left&&root->right){
                a=fun(root->left,m,m2,m3,1)+fun(root->right,m,m2,m3,0);
                b=fun(root->left,m,m2,m3,0)+fun(root->right,m,m2,m3,1);
                // c=fun(root->left,m,m2,m3)
                ntake=min(a,b);
            }
            else if(root->left){
                ntake=min(ntake,fun(root->left,m,m2,m3,1));
            }
            else if(root->right){
                ntake=min(ntake,fun(root->right,m,m2,m3,1));
            }
            return m[root] = min(take, ntake);
        }
        else{
            //comp==-1
            int take=1;
            int ntake=0;
            if (root->left) {
                take += fun(root->left, m, m2,m3, -1);
                ntake += fun(root->left, m, m2,m3, 0);
            }
            if (root->right) {
                take += fun(root->right, m, m2,m3, -1);
                ntake += fun(root->right, m, m2,m3, 0);
            }
            return m3[root] = min(take, ntake);
        }
    }

public:
    int minCameraCover(TreeNode* root) {
        unordered_map<TreeNode*, int> m,m2,m3;
        
        if(root->left==NULL&&root->right==NULL){
            return 1;
        }
        return fun(root, m, m2,m3, 0);
    }
};