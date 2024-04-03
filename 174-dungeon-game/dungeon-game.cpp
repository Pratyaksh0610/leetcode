class Solution {
    private:
    int fun(vector<vector<int>>&d,int i,int j,vector<vector<int>>&dp){
        int r=d.size(),c=d[0].size();
        if(i>=r||j>=c){
            return 1e9;
        }
        else if(dp[i][j]!=1e9){
            return dp[i][j];
        }
        else if(i==r-1&&j==c-1){
            if(d[i][j]>=0){
                return dp[i][j]= 1;
            }
            return dp[i][j]= 1-d[i][j];
        }
        int b=fun(d,i+1,j,dp);
        int rr=fun(d,i,j+1,dp);
        int mini=min(b,rr);
        mini-=d[i][j];
        if(mini>0){
            return dp[i][j]= mini;
        }
        return dp[i][j]= 1;
    }
public:
    int calculateMinimumHP(vector<vector<int>>& d) {
        int r=d.size(),c=d[0].size();
        vector<vector<int>>dp(r,vector<int>(c,1e9));
        return fun(d,0,0,dp);
    }
};