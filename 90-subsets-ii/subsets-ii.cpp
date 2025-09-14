class Solution {
    void generateSubsets(vector<int>temp,vector<int>&nums,int index,set<vector<int>>&s){
        if((index)==nums.size()){
            s.insert(temp);
            return;
        }
        //ntake
        int val=nums[index];
        generateSubsets(temp,nums,index+1,s);
        //take
        temp.push_back(val);
        generateSubsets(temp,nums,index+1,s);
        return;
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>s;
        sort(nums.begin(),nums.end());
        // for(auto it:nums){
        //     s.insert(it);
        // }
        vector<vector<int>>ans;
        vector<int>temp;
        generateSubsets(temp,nums,0,s);
        for(auto it:s){
            ans.push_back(it);
        }
        return ans;
    }
};