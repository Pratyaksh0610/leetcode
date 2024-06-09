class Solution {
    private:
    int fun(vector<vector<int>>&dp,vector<int>&nums,int ind,int tot){
        if(ind>=nums.size()){
            return 0;
        }
        else if(dp[ind][tot]!=-1){
            return dp[ind][tot];
        }
        //ntake
        int ntake=0+fun(dp,nums,ind+1,tot);
        int sum=tot+nums[ind];
        int si=ind+1,ei=nums.size()-1;
        int nind=nums.size();
        while(si<=ei){
            int mid=si+(ei-si)/2;
            if(nums[mid]>sum){
                ei=mid-1;
                nind=mid;
            }
            else{
                si=mid+1;
            }
        }
        int take=nums[ind]+fun(dp,nums,nind,sum);
        return dp[ind][tot]= max(take,ntake);
        // return nums[ind]+ans;
    }
public:
    int maxTotalReward(vector<int>& r) {
        int n=r.size();
        vector<vector<int>>dp(n,vector<int>(4000,-1));
        // vector<int>dp(n,-1);
        sort(r.begin(),r.end());
        // int ans=0;
        return fun(dp,r,0,0);
        // for(int i=0;i<n;i++){
        //     ans=max(ans,fun(r,i,0));
        // }
        // return ans;
    }
};