class Solution {
    private:
    int fun(vector<vector<int>>&g,vector<vector<int>>&dp,int i,int j){
        int r=g.size(),c=g[0].size();
        if(i<0||i>=r||j<0||j>=c){
            return 1e8;
        }
        else if(i==r-1){
            return dp[i][j]= g[i][j];
        }
        else if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int val=INT_MAX;
        for(int k=0;k<c;k++){
            if(k==j){
                continue;
            }
            val=min(val,fun(g,dp,i+1,k));
        }
        return dp[i][j]=val+g[i][j];
    }
public:
    int minFallingPathSum(vector<vector<int>>& g) {
        int r=g.size(),c=g[0].size();
        vector<vector<int>>dp(r,vector<int>(c,-1));
        int ans=INT_MAX;
        for(int j=0;j<c;j++){
            ans=min(ans,fun(g,dp,0,j));
        }
        return ans;
    }
};