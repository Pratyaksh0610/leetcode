const int mod=1e9+7;
class Solution {
    private:
    int lim=-1;
    int fun(int remsteps,int ind,vector<vector<int>>&dp){
        if(ind<0||ind>lim){
            return 0;
        }
        if(remsteps==0){
            if(ind==0){
                return 1;
            }
            return 0;
        }
        else if(dp[remsteps][ind]!=-1){
            return dp[remsteps][ind]%mod;
        }
        int ans=0;
        ans+=fun(remsteps-1,ind+1,dp)%mod;
        ans=ans%mod;
        ans+=fun(remsteps-1,ind-1,dp)%mod;
                ans=ans%mod;

        ans+=fun(remsteps-1,ind,dp)%mod;
                ans=ans%mod;

        return dp[remsteps][ind]=ans%mod;
    }
public:
    int numWays(int steps, int n) {
        int poss=(steps+1)/2;
        lim=min(poss,n-1);
        cout<<lim<<endl;
        vector<vector<int>>dp(steps+1,vector<int>(lim+1,-1));
        return fun(steps,0,dp)%mod;
    }
};