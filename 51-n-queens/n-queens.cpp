class Solution {
private:
    bool rowCheck(vector<vector<bool>>& vis, int i, int n) {
        if (i >= n || i < 0) {
            return false;
        }
        for(int j=0;j<n;j++){
            if(vis[i][j]){
                return false;
            }
        }
        return true;
    }
    bool colCheck(vector<vector<bool>>& vis, int j, int n) {
        if (j >= n || j < 0) {
            return false;
        }
        for(int i=0;i<n;i++){
            if(vis[i][j]){
                return false;
            }
        }
        return true;
    }
    bool diagonalCheck(vector<vector<bool>>& vis, int i, int j, int n) {
        if (j >= n || j < 0||i>=n||i<0) {
            return false;
        }
        vector<int>r={-1,1};
        vector<int>c={-1,1};
        for(int rr=0;rr<2;rr++){
            for(int cc=0;cc<2;cc++){
                int sr=i,sc=j;
                while(sr<n&&sr>=0&&sc>=0&&sc<n){
                    if(vis[sr][sc]){
                        return false;
                    }
                    sr+=r[rr];
                    sc+=c[cc];
                }
            }
        }
        return true;
    }
    void fun(vector<vector<string>>& ans, vector<vector<bool>>& vis, int r, int n) {
        if (r >= n) {
            // cout<<"AAYA"<<endl;
            vector<string>temp;
            for(int i=0;i<n;i++){
                string s;
                for(int j=0;j<n;j++){
                    if(vis[i][j]){
                        s=s+'Q';
                    }
                    else{
                        s=s+'.';
                    }
                }
                temp.push_back(s);
            }
            ans.push_back(temp);
            return;
        }
        bool checkRow =rowCheck(vis,r,n);
        if(checkRow==false){
            return;
        }
        for(int c=0;c<n;c++){
            bool checkCol =colCheck(vis,c,n);
            bool checkDiagonals =diagonalCheck(vis,r,c,n);
            if(checkCol&&checkDiagonals){
                vis[r][c]=true;
                fun(ans,vis,r+1,n);
                vis[r][c]=false;
            }
        }
        return;
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        // vector<string> v;
        fun(ans, vis, 0, n);
        return ans;
    }
};