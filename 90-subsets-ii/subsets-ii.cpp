class Solution {
    set<vector<int>>s;
    void fun(vector<int>&nums,int ind,vector<int>temp){
        if(ind>=nums.size()){
            s.insert(temp);
            return;
        }
        fun(nums,ind+1,temp);
        temp.push_back(nums[ind]);
        fun(nums,ind+1,temp);
        return;
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>temp;
        sort(nums.begin(),nums.end());
        fun(nums,0,temp);
        vector<vector<int>>ans;
        for(auto it:s){
            ans.push_back(it);
        }
        return ans;
    }
};