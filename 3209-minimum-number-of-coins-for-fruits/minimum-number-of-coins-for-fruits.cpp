class Solution {
    private:
    int fun(vector<int>&p,int ind,int allow,vector<vector<int>>&dp){
        if(ind>=p.size()){
            return 0;
        }
        else if(dp[ind][allow]!=-1){
            return dp[ind][allow];
        }
        int take=p[ind]+fun(p,ind+1,ind+1,dp);
        int ntake=1e8;
        if(allow>=1){
            ntake=fun(p,ind+1,allow-1,dp);
        }
        return dp[ind][allow]= min(take,ntake);
    }
public:
    int minimumCoins(vector<int>& p) {
        int n=p.size();
        // vector<int>dp(n,-1);
        vector<vector<int>>dp(n,vector<int>(n+1,-1));
        return fun(p,0,0,dp);
    }
};