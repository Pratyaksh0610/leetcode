#define pi pair<int,int>

class Solution {
public:
    int minTaps(int n, vector<int>& r) {
        vector<pi>v;
        for(int i=0;i<r.size();i++){
            v.push_back({i-r[i],i+r[i]});
        }
        sort(v.begin(),v.end());
        priority_queue<int>pq;
        int allow=0,ans=0;
        int i=0;
        while(i<v.size()){
            if(v[i].first<=allow){
                pq.push(v[i].second);
                i++;
                // cout<<allow<<endl;
            }
            else if(v[i].first>allow){
                if(pq.empty()){
                    return -1;
                }
                allow=pq.top();
                pq.pop();
                ans++;
                // cout<<allow<<endl;
                if(allow>=n){
                    return ans;
                }
            }
        }
        if(pq.top()>=n){
            return ans+1;
        }
        return -1;
    }
};