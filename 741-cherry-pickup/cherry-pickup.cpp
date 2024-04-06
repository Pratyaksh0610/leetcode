class Solution {
    private:
    int fun(vector<vector<vector<vector<int>>>>&dp,vector<vector<int>>& g,int i,int j,int k,int l){
        int n=g.size();
        if(i<0||i>=n||j<0||j>=n||k<0||k>=n||l<0||l>=n||g[i][j]==-1||g[k][l]==-1){
            return -1e8;
        }
        else if(dp[i][j][k][l]!=-1){
            return dp[i][j][k][l];
        }
        else if(i==n-1&&j==n-1){
            // g[i][j]=0;
            return g[i][j];
        }
        else if(k==n-1&&l==n-1){
            // g[k][l]=0;
            return g[k][l];
        }
        else{
            int val=g[i][j]+g[k][l];
            int a=g[i][j],b=g[k][l];
            if(i==k&&j==l){
                val-=a;
            }
            g[i][j]=0,g[k][l]=0;
            int v1=fun(dp,g,i+1,j,k+1,l);
            int v2=fun(dp,g,i+1,j,k,l+1);
            int v3=fun(dp,g,i,j+1,k+1,l);
            int v4=fun(dp,g,i,j+1,k,l+1);
            g[i][j]=a,g[k][l]=b;
            return dp[i][j][k][l]=val+ max(v1,max(v2,max(v3,v4)));
        }
        
    }
public:
    int cherryPickup(vector<vector<int>>& g) {
        int n=g.size();
        vector<vector<vector<vector<int>>>>dp(n,vector<vector<vector<int>>>(n,vector<vector<int>>(n,vector<int>(n,-1))));
        int val= fun(dp,g,0,0,0,0);
        if(val<0){
            return 0;
        }
        return val;
    }
};