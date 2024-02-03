#define ll long long int
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        ll ans=LLONG_MIN,sum=0;
        unordered_map<ll,ll>m;
        bool f=false;
        vector<ll>pref;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            ll v1=nums[i]+k;
            ll v2=nums[i]-k;
            if(m.find(v1)!=m.end()){
                f=true;
                ll ind=m[v1];
                ind--;
                ll a=sum;
                if(ind>=0){
                    a-=pref[ind];
                }
                ans=max(ans,a);
            }
            if(m.find(v2)!=m.end()){
                f=true;
                ll ind=m[v2];
                ind--;
                ll a=sum;
                if(ind>=0){
                    a-=pref[ind];
                }
                ans=max(ans,a);
            }
            pref.push_back(sum);
            if(m.find(nums[i])==m.end()){
                m[nums[i]]=i;
            }
            else{
                ll val=pref[m[nums[i]]];
                if(val==sum){
                    continue;
                }
                else if(val>sum){
                    m[nums[i]]=i;
                }
                // else{

                // }
            }
        }
        if(f==false){
            return 0;
        }
        return ans;

    }
};