#define ll long long int

class Solution {
public:
    long long appealSum(string s) {
        ll n=s.size(),ans=0;
        unordered_map<char,ll>m,p;
        vector<ll>next(n,-1),prev(n,-1);
        for(ll i=n-1;i>=0;i--){
            if(m.find(s[i])!=m.end()){
                next[i]=m[s[i]];
            }
            m[s[i]]=i;
        }
        for(ll i=0;i<n;i++){
            if(p.find(s[i])!=p.end()){
                prev[i]=p[s[i]];
            }
            p[s[i]]=i;
        }

        // for(int i=0;i<n;i++){
        //     cout<<next[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<n;i++){
        //     cout<<prev[i]<<" ";
        // }

        for(ll i=0;i<n;i++){
            // ll pval=prev[i];
            ll nval=next[i]-i;
            if(nval<0){
                nval=n-i;
            }
            ll m1=i+1;
            ans+=(m1)*(nval);
        }
        return ans;
        
    }
};
