class Solution {
    private:
    void fun(vector<vector<int>>&ans,vector<int>&nums,int ind,vector<int>temp){
        if(ind>=nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            if(i!=ind&&nums[i]==nums[i-1]){
                continue;
            }
            temp.push_back(nums[i]);
            fun(ans,nums,i+1,temp);
            temp.pop_back();
        }
        ans.push_back(temp);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>temp;
        fun(ans,nums,0,temp);
        return ans;
    }
};