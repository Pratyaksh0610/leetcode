class Solution {
    private:
    int fun(vector<string>&v,unordered_map<string,int>&dp,unordered_map<char,set<int>>&m,string &s){
        if(s.size()==0){
            return 0;
        }
        else if(dp.find(s)!=dp.end()){
            return dp[s];
        }
        vector<int>temp(26,0);
        for(int i=0;i<s.size();i++){
            temp[s[i]-'a']++;
        }
        int ans=1e8;
        for(int i=0;i<s.size();i++){
            for(auto it:m[s[i]]){
                //it is index for v
                for(int j=0;j<v[it].size();j++){
                    // if(temp[v[it][j]-'a']>0){
                        temp[v[it][j]-'a']--;
                    // }
                }
                string child;
                for(int j=0;j<26;j++){
                    for(int k=0;k<temp[j];k++){
                        child.push_back('a'+j);
                    }
                }
                ans=min(ans,1+fun(v,dp,m,child));
                for(int j=0;j<v[it].size();j++){
                    // if(temp[v[it][j]-'a']>0){
                        temp[v[it][j]-'a']++;
                    // }
                }
            }
        }
        return dp[s]=ans;
    }
public:
    int minStickers(vector<string>& st, string t) {
        sort(t.begin(),t.end());
        // cout<<t<<endl;
        unordered_map<string,int>dp;
        unordered_map<char,set<int>>s;
        for(int i=0;i<st.size();i++){
            for(int j=0;j<st[i].size();j++){
                s[st[i][j]].insert(i);
            }
        }
        for(int i=0;i<t.size();i++){
            if(s[t[i]].size()==0){
                return -1;
            }
        }
        return fun(st,dp,s,t);
    }
};