#define ll long long int
#define pi pair<int,int>
class Solution {
    private:
    int r=-1,c=-1;
    const int mod=1e9+7;
    ll fun(vector<vector<vector<ll>>>&dp,int i,int j,int moves,int col[],int row[]){
        if(i<0||i>=r||j<0||j>=c){
            return 1;
        }
        else if(dp[i][j][moves]!=-1){
            return dp[i][j][moves];
        }
        else if(moves==0){
            return 0;
        }
        ll val=0;
        for(int k=0;k<4;k++){
            val+=fun(dp,i+row[k],j+col[k],moves-1,col,row);
        }
        return dp[i][j][moves]=val%mod;
    }
public:
    int findPaths(int m, int n, int mm, int i, int j) {
        vector<vector<vector<ll>>>dp(m+1,vector<vector<ll>>(n+1,vector<ll>(mm+1,-1)));
        int col[]={-1,0,1,0};
        int row[]={0,-1,0,1};
        // int mod=1e9+7;
        r=m,c=n;
        ll ans=fun(dp,i,j,mm,col,row);
        return ans%mod;
    }
};