class Solution {
    private:
    void fun(set<vector<int>>&ans,deque<int>&dq,vector<int>&vis,vector<int>&nums){
        if(dq.size()==nums.size()){
            vector<int>temp;
            for(auto it:dq){
                temp.push_back(it);
            }
            ans.insert(temp);
            return;
        }
        bool added=false;
        for(int i=0;i<vis.size();i++){
            if(vis[i]==-1){
                dq.push_front(nums[i]);
                vis[i]=1;
                fun(ans,dq,vis,nums);
                dq.pop_front();
                dq.push_back(nums[i]);
                fun(ans,dq,vis,nums);
                dq.pop_back();
                vis[i]=-1;
            }
        }
        return;
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        // vector<int>temp = {nums[0]};
        set<vector<int>>ans;
        vector<int>vis(nums.size(),-1);
        vis[0]=1;
        // unordered_map<int,int>m;
        deque<int>dq;
        dq.push_front(nums[0]);
        // for(int i=1;i<nums.size();i++){
        //     m[nums[i]]++;
        // }
        // m[nums[0]]=true;
        fun(ans,dq,vis,nums);
        vector<vector<int>>fans;
        for(auto it:ans){
            fans.push_back(it);
        }
        return fans;
    }
};