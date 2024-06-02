class Solution {
      void fun(vector<vector<int>>&ans,vector<int>&nums,int ind,vector<int>temp,int t){
        if(ind>=nums.size()){
            if(t==0){
                ans.push_back(temp);
            }
            return;
        }
        fun(ans,nums,ind+1,temp,t);
        while(t>=nums[ind]){
            t-=nums[ind];
            temp.push_back(nums[ind]);
            fun(ans,nums,ind+1,temp,t);
        }
        return;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>temp;
        fun(ans,nums,0,temp,target);
        return ans;
    }
};