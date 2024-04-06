class Solution {
private:
    int fun(int i, int j1, int j2, vector<vector<int>>& g,
            vector<vector<vector<int>>> &dp) {
        int r = g.size(), c = g[0].size();
        if (i < 0 || i >= r || j1 < 0 || j1 >= c || j2 < 0 || j2 >= c) {
            return -1e8;
        }
        int val = g[i][j1] + g[i][j2];
        if (j1 == j2) {
            val -= g[i][j1];
        }
        if (i == r - 1) {
            return dp[i][j1][j2] = val;
        } else if (dp[i][j1][j2] != -1) {
            return dp[i][j1][j2];
        }
        vector<pair<int, int>> v = {{1, -1}, {1, 0}, {1, 1}};
        int ans = val;
        for (int k = 0; k < 3; k++) {
            // cout<<v[k].first<<" "<<v[k].second<<endl;
            for (int l = 0; l < 3; l++) {
                // int sub=fun(i1+v[k].first,j1+v[k].second,i2+v[l].first,j2+)
                int v1 = val + fun(i + v[k].first, j1 + v[k].second,
                                   j2 + v[l].second, g, dp);
                ans = max(ans, v1);
            }
        }
        return dp[i][j1][j2] = ans;
    }

public:
    int cherryPickup(vector<vector<int>>& g) {
        int r = g.size(), c = g[0].size();
        vector<vector<vector<int>>> dp(
            r, vector<vector<int>>(c, vector<int>(c, -1)));
        // vector<vector<int>>dp(r,vector<int>(c,-1));
        return fun(0, 0, c - 1, g, dp);
    }
};