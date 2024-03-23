class Solution {
    int fun(vector<vector<int>>& m, vector<vector<int>>& dp, int i, int j) {
        if (i >= m.size() || j >= m[0].size() || i < 0 || j < 0) {
            return 0;
        } else if (dp[i][j] != -1) {
            return dp[i][j];
        }
        int col[] = {-1, 0, 1, 0};
        int row[] = {0, 1, 0, -1};
        int ans = 1;
        for (int k = 0; k < 4; k++) {
            int rind = i + row[k], cind = j + col[k];
            if (rind >= m.size() || cind >= m[0].size() || rind < 0 ||
                cind < 0 || m[rind][cind] <= m[i][j]) {
                continue;
            }
            ans = max(ans,1+ fun(m, dp, rind, cind));
        }
        return dp[i][j] = ans;
    }

public:
    int longestIncreasingPath(vector<vector<int>>& m) {
        int r = m.size(), c = m[0].size();
        vector<vector<int>> dp(r, vector<int>(c, -1));
        int maxi=1;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                maxi=max(maxi,fun(m,dp,i,j));
            }
        }
        return maxi;
    }
};