#define ll long long int

class Solution {
public:
    long long minEnd(ll n, ll x) {
        ll num=n-1;
        if(num==0){
            return x;
        }
        ll ans=x;
        ll ind=0;
        
        while(num>0){
            ll c1=(ll)1<<ind;
            if(x&(c1)){
                ind++;
            }
            else{
                ll val=(1&num);
                num=num>>1;
                ans=ans|(val<<ind);
                ind++;
            }
        }
        return ans;
    }
};