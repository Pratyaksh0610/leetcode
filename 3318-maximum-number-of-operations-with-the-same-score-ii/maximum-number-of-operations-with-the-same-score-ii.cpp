class Solution {
    private:
    int fun(vector<int>&nums,int i,int j,int target,vector<vector<int>>&dp){
        if(i>=j){
            return 0;
        }
        else if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int a=0,b=0,c=0;
        if(i+1<=j&&nums[i]+nums[i+1]==target){
            a=1+fun(nums,i+2,j,target,dp);
        }
        if(j-1>=i&&nums[j]+nums[j-1]==target){
            b=1+fun(nums,i,j-2,target,dp);
        }
        if(nums[i]+nums[j]==target){
            c=1+fun(nums,i+1,j-1,target,dp);
        }
        return dp[i][j]= max(a,max(b,c));
    }
public:
    int maxOperations(vector<int>& nums) {
        int n=nums.size();
        int st=nums[0]+nums[1],end=nums[n-2]+nums[n-1],mid=nums[0]+nums[n-1];
        vector<vector<int>>dp1(n,vector<int>(n,-1));
        // vector<vector<int>>dp3(n,vector<int>(n,-1));
        // vector<vector<int>>dp2(n,vector<int>(n,-1));

        // map<pair<int,int>,int>dp1,dp2,dp3;
        int a=1+fun(nums,2,n-1,st,dp1);
        int b=1+fun(nums,0,n-3,end,dp1);
        int c=1+fun(nums,1,n-2,mid,dp1);
        return max(a,max(b,c));
    }
};