class Solution {
    private:
    int fun(vector<int>&p,int ind,vector<int>&dp){
        if(ind>=p.size()){
            return 0;
        }
        else if(dp[ind]!=-1){
            return dp[ind];
        }
        int ans=INT_MAX;
        for(int i=ind+1;i<=2*ind+2;i++){
            ans=min(ans,p[ind]+fun(p,i,dp));
        }
        // int take=p[ind]+fun(p,ind+1,ind+1,dp);
        // int ntake=1e8;
        // if(allow>=1){
        //     ntake=fun(p,ind+1,allow-1,dp);
        // }
        return dp[ind]= ans;
    }
public:
    int minimumCoins(vector<int>& p) {
        int n=p.size();
        // vector<int>dp(n,-1);
        vector<int>dp(n,-1);
        return fun(p,0,dp);
    }
};