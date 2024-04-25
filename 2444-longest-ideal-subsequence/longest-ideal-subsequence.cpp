class Solution {
public:
    int longestIdealString(string s, int k) {
        int n=s.size();
        // vector<int>alpha(26,-1);
        unordered_map<char,int>m;
        vector<int>dp(n,0);
        for(int i=0;i<n;i++){
            char ch=s[i];
            int mini=ch-'a'-k,maxi=ch-'a'+k;
            mini=max(mini,0);
            maxi=min(maxi,25);
            int curr=1;
            for(;mini<=maxi;mini++){
                char temp='a'+mini;
                if(m.find(temp)==m.end()){
                    continue;
                }
                else{
                    int ind=m[temp];
                    curr=max(curr,dp[ind]+1);
                }
            }
            m[ch]=i;
            dp[i]=curr;
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};