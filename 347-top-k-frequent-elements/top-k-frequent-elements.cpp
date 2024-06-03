#define pi pair<int,int>

class compa{
    public:
    bool operator()(pi &a,pi &b){
        if(a.second>b.second){
            return true;
        }
        return false;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        priority_queue<pi,vector<pi>,compa>pq;
        for(auto it:m){
            // int val=it.first,freq=it.second;
            pq.push(it);
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<int>ans;
        while(pq.size()){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};