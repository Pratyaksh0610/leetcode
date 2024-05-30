class Solution {
    private:
    int fun(vector<int>&c,int am,int ind,vector<vector<int>>&dp){
        if(ind<0){
            return 1e8;
        }
        else if(am==0){
            return 0;
        }
        else if(dp[ind][am]!=-1){
            return dp[ind][am];
        }
        int ans=1e8;
        if(c[ind]>am){
            ans=min(ans,fun(c,am,ind-1,dp));
        }
        else{
            ans=min(ans,1+fun(c,am-c[ind],ind,dp));
        }
        ans=min(ans,fun(c,am,ind-1,dp));
        return dp[ind][am]= ans;
    }
public:
    int coinChange(vector<int>& c, int am) {
        sort(c.begin(),c.end());
        vector<vector<int>>dp(c.size(),vector<int>(am+1,-1));
        int ans= fun(c,am,c.size()-1,dp);
        if(ans>1e4) return -1;
        return ans;
    }
};