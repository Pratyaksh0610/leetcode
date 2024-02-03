class Solution {
    int fun(vector<int>&arr,int si,int ei,int k,vector<vector<int>>&dp){
        if(si>ei){
            return 0;
        }
        else if(si==ei){
            return arr[si];
        }
        else if(dp[si][ei]!=-1){
            return dp[si][ei];
        }
        int maxi=0;
        int ele=-1;
        for(int i=si;i<(si+k);i++){
            if(i>ei){
                break;
            }
            ele=max(ele,arr[i]);
            int sum=((i-si+1)*ele)+fun(arr,i+1,ei,k,dp);
            maxi=max(maxi,sum);
        }
        return dp[si][ei]= maxi;
    }
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        //partition dp lgegi
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return fun(arr,0,arr.size()-1,k,dp);
    }
};