class Solution {
    private:
    bool isPalindrome(string &s,int st,int end){
        if(s.empty()){
            return true;
        }
        while(st<end){
            if(s[st]!=s[end]){
                return false;
            }
            st++;
            end--;
        }
        return true;
    }
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        // for(int i=0;i<n;i++){
        //     dp[0][i]=isPalindrome(s,0,i);
        // }
        for(int i=n-1;i>=0;i--){
            dp[i][i]=true;
            for(int j=i+1;j<n;j++){
                if(s[i]==s[j]){
                    dp[i][j]=(dp[i+1][j-1]);
                    if(i+1==j){
                        dp[i][j]=max(dp[i][j],dp[i+1][j]);
                    }
                }
            }
        }
        int ans=1;
        string temp;
        temp.push_back(s[0]);
        for(int i=0;i<n;i++){
            int si=i,ei=n-1;
            while(si<n&&dp[i][si]==false){
                si++;
            }
            while(ei>=0&&dp[i][ei]==false){
                ei--;
            }
            int val=ei-si;
            if(val+1>ans){
                ans=val;
                temp=s.substr(si,val+1);
            }
        }
        // cout<<ans<<" "<<temp;
        return temp;
    }
};