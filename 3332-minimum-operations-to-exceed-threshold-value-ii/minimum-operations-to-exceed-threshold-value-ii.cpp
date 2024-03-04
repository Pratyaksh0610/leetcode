#define ll long long int
class Solution {
public:
    int minOperations(vector<int>& nums, ll k) {
        priority_queue<ll,vector<ll>,greater<ll>>pq;
        ll n=nums.size();
        for(ll i=0;i<n;i++){
            pq.push(nums[i]);
        }
        ll curr=0;
        while(pq.size()>=2){
            ll a=pq.top();
            if(a>=k){
                return curr;
            }
            pq.pop();
            ll b=pq.top();
            curr++;
            pq.pop();
            pq.push(min(a,b)*2+max(a,b));
        }
        return curr;
    }
};