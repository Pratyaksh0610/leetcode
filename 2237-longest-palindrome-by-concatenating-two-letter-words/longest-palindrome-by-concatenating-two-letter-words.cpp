#define ll long long int
class Solution {
public:
    int longestPalindrome(vector<string>& w) {
        unordered_map<string,ll>m;
        for(int i=0;i<w.size();i++){
            m[w[i]]++;
        }
        ll ans=0;
        for(auto it:m){
            ll freq=it.second;
            if(it.first[0]==it.first[1]){
                continue;
            }
            string temp=it.first;
            reverse(temp.begin(),temp.end());
            if(m.find(temp)==m.end()){
                continue;
            }
            else{
                ll len=min((ll)freq,(ll)m[temp]);
                ans+=(len)*4;
            }
        }
        ans/=2;
        ll maxi=0,even=0;
        bool odd=false;
        for(auto it:m){
            if(it.first[0]!=it.first[1]){
                continue;
            }
            if(it.second%2==0){
                even+=it.second;
            }
            else{
                odd=true;
                even+=it.second-1;
            }
        }
        if(odd){
            even++;
        }
        ans+=(even)*2;
        return ans;
    }
};