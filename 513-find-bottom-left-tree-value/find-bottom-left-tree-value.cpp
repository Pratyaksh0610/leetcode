class Solution {
public:
     pair<int,int>l;
     pair<int,int>r;
   pair<int,int>bottom(TreeNode*root,int level){
      if(root->left!=NULL){
           pair<int,int>temp = bottom(root->left,level+1);
           if(temp.second>l.second){
             l=temp;
           }
       }
       
      if(root->right!=NULL){
           pair<int,int>temp = bottom(root->right,level+1);
           if(temp.second>r.second){
             r=temp;
           }
       }
      if(root->left==NULL&&root->right==NULL){
        pair<int,int>temp;
        temp.first = root->val;
        temp.second = level;
        return temp;
      }
      return l.second>=r.second?l:r;
   }
    int findBottomLeftValue(TreeNode* root) {
     pair<int,int>ans;
     ans = bottom(root,1);
     return ans.first;
    }
};