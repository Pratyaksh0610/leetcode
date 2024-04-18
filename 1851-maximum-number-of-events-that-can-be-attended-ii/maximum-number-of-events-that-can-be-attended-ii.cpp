class Solution {
    private:
    int fun(vector<vector<int>>& e, int k,int ind,vector<vector<int>>&dp){
        if(ind>=e.size()||k<=0){
            return 0;
        }
        else if(dp[ind][k]!=-1){
            return dp[ind][k];
        }
        int st=e[ind][0],end=e[ind][1];
        int ntake=0+fun(e,k,ind+1,dp);
        int nind=e.size();
        int si=ind+1,ei=e.size()-1;
        while(si<=ei){
            int mid=si+(ei-si)/2;
            if(e[mid][0]>end){
                nind=mid;
                ei=mid-1;
            }
            else{
                si=mid+1;
            }
        }
        int take=e[ind][2]+fun(e,k-1,nind,dp);
        return dp[ind][k]= max(take,ntake);
    }
public:
    int maxValue(vector<vector<int>>& e, int k) {
        int n=e.size();
        sort(e.begin(),e.end());
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return fun(e,k,0,dp);
    }
};