class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
        for(int i=0;i<n;i++){
            for(int j=n-1;j>=i;j--){
                bool done=true;
                if(dp[i][j]){
                    continue;
                }
                int ii=i,jj=j;
                while(ii<=jj){
                    if(s[ii]!=s[jj]){
                        done=false;
                        break;
                    }
                    ii++;
                    jj--;
                }
                if(done){
                    ii=i,jj=j;
                    while(ii<=jj){
                        dp[ii][jj]=true;
                        ii++;
                        jj--;
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(dp[i][j]==true){
                    ans++;
                }
            }
        }
        return ans;
    }
};