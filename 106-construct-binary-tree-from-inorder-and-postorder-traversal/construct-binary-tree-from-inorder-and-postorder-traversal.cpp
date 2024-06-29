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
 class Solution{
    TreeNode*fun(vector<int>& pos, vector<int>& ino,int ps,int pe,int is,int ie){
        if(ps>pe||is>ie){
            return NULL;
        }
        int rootVal=pos[pe];
        int rootInd=-1;
        for(int i=is;i<=ie;i++){
            if(ino[i]==rootVal){
                rootInd=i;
                break;
            }
        }
        int leftLength=rootInd-is;
        TreeNode*root=new TreeNode(rootVal);
        root->left=fun(pos,ino,ps,ps+leftLength-1,is,rootInd-1);
        root->right=fun(pos,ino,ps+leftLength,pe-1,rootInd+1,ie);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& ino, vector<int>& pos) {
        int n=ino.size();
        return fun(pos,ino,0,n-1,0,n-1);
    }
};