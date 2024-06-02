class Solution {
private:
    void fun(vector<vector<int>>& ans, vector<int>& nums, int ind,
             vector<int> temp, int t) {
        if (ind >= nums.size()||t==0||t<0) {
            if (t == 0) {
                ans.push_back(temp);
            }
            return;
        }
        for(int i=ind;i<nums.size();i++){
            if(i!=ind&&nums[i]==nums[i-1]){
                continue;
            }
            if(nums[i]>t){
                break;
            }
            temp.push_back(nums[i]);
            fun(ans,nums,i+1,temp,t-nums[i]);
            temp.pop_back();
        }
        return;
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> temp;
        fun(ans, nums, 0, temp, target);
        return ans;
    }
};