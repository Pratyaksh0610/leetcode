class Solution {
    private:
    int fun(string &s,unordered_map<string,bool>&m,vector<int>&dp,int index){
        if(index>=s.size()){
            return 1;
        }
        else if(dp[index]!=-1){
            return dp[index];
        }
        int isPossible = 0;
        string temp="";
        for(int i=index;i<s.size();i++){
            temp+=s[i];
            if(m.find(temp)!=m.end()){
                isPossible = isPossible | fun(s,m,dp,i+1);
            }
        }
        return dp[index]=isPossible;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        vector<int>dp(n,-1);
        unordered_map<string,bool>m;
        for(auto it:wordDict){
            m[it]=true;
        }
        return fun(s,m,dp,0);
        // return false;
    }
};