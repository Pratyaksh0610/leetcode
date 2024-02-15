#define ll long long int
class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        ll val=1;
        //neg,pos,0
        ll n=nums.size();
        ll curr=0,neg=1e10;
        ll ans=0;
        for(ll i=0;i<n;i++){
            val*=nums[i];
            curr++;
            if(val>0){
                val=1;
                ans=max(ans,curr);
            }
            else if(val<0){
                val=-1;
                neg=min(neg,i);
                ans=max(ans,i-neg);
            }
            if(val==0){
                curr=0;
                neg=1e10;
                val=1;
            }
        }
        if(ans<0){
            return 0;
        }
        return ans;
    }
};