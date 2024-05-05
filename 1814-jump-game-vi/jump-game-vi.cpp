#define pi pair<int,int>

class Solution {
    // int fun(vector<int>&nums,int ind,int k,vector<int>&dp){
    //     if(ind>=nums.size()){
    //         return -1e8;
    //     }
    //     else if(ind==nums.size()-1){
    //         return nums[ind];
    //     }
    //     else if(dp[ind]!=-1e9){
    //         return dp[ind];
    //     }
    //     int ans=-1e8;
    //     for(int i=1;i<=k;i++){
    //         if(ind+i>=nums.size()){
    //             break;
    //         }
    //         ans=max(ans,fun(nums,ind+i,k,dp));
    //     }
    //     return dp[ind]= ans+nums[ind];
    // }
public:
    int maxResult(vector<int>& nums, int k) {
        int n=nums.size();
        // vector<int>dp(n,-1e9);
        // return fun(nums,0,k,dp);
        priority_queue<pi>pq;
        pq.push({nums[n-1],n-1});
        if(n==1){
            return nums[n-1];
        }
        for(int i=n-2;i>=0;i--){
            while(pq.size()&&pq.top().second>i+k){
                pq.pop();
            }
            pi temp=pq.top();
            pq.push({temp.first+nums[i],i});
            if(i==0){
                return temp.first+nums[i];
            }
        }
        return -1;
    }
};