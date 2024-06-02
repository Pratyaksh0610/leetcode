class Solution {
    void fun(vector<vector<int>>&ans,vector<int>&nums,int ind,vector<int>temp){
        if(ind>=nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[ind]);
        for(int i=0;i<temp.size();i++){
            swap(temp[i],temp[temp.size()-1]);
            fun(ans,nums,ind+1,temp);
            swap(temp[i],temp[temp.size()-1]);
        }
        return;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        fun(ans,nums,0,temp);
        return ans;
    }
};