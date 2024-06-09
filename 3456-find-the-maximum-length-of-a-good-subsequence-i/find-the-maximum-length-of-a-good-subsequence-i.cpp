class Solution {
    private:
    int fun(vector<vector<int>>&dp,vector<int>&nums,int ind,int cost,int k){
        if(ind>=nums.size()||cost>k){
            return 0;
        }
        else if(dp[ind][cost]!=-1){
            return dp[ind][cost];
        }
        int ans=1;
        for(int j=ind+1;j<nums.size();j++){
            int val=0;
            if(nums[j]==nums[ind]){
                val=1+fun(dp,nums,j,cost,k);
            }
            else if(cost<k){
                val=1+fun(dp,nums,j,cost+1,k);
            }
            ans=max(ans,val);
        }
        // ans=max(ans,fun(nums,ind+1,0,k));
        // ans=max(ans)
        return dp[ind][cost] =ans;
    }
public:
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=0;
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        for(int i=0;i<n;i++){
            maxi=max(maxi,fun(dp,nums,i,0,k));
        }
        return maxi;
        // return fun(nums,0,0,k);
    }
};