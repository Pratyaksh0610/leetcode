#define pi pair<int,int>

class compa{
    public:
    bool operator()(pi &a , pi &b){
        if(a.first>b.first){
            return false;
        }
        return true;
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pi,vector<pi>,compa>pq;
        int i=0,cnt=0,n=nums.size();
        while(i<n&&cnt<k){
            pq.push({nums[i],i});
            i++;
            cnt++;
        }
        vector<int>ans;
        ans.push_back(pq.top().first);
        while(i<n){
            pq.push({nums[i],i});
            while(pq.size()&&abs(pq.top().second-i)>=k){
                pq.pop();
            }
            ans.push_back(pq.top().first);
            i++;
        }
        return ans;
    }
};