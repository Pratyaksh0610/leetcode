#define ll long long int
#define pi pair<int,int>
const int mod=1e9+7;

class Solution {
public:
    int maxPerformance(int n, vector<int>& sp, vector<int>& eff, int k) {
        vector<pi>v;
        for(int i=0;i<n;i++){
            v.push_back({eff[i],sp[i]});
        }
        sort(v.begin(),v.end());
        priority_queue<ll,vector<ll>,greater<ll>>pq;

        ll sum=0,ans=0;

        for(int i=v.size()-1;i>=0;i--){
            ll mul=v[i].first;

            pq.push(v[i].second);
            sum+=v[i].second;

            while(pq.size()>k){
                sum-=pq.top();
                pq.pop();
            }
            ll val=(sum*mul);
            ans=max(ans,val);
        }
        return ans%mod;
    }
};