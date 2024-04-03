#define ll long long int
const int mod = 1e9 + 7;
class Solution {
private:
    int ans = 0;
    int fun(int mini, int ind, int pp, vector<int>& g, vector<int>& p,
            vector<vector<vector<int>>>& dp) {
        if (mini < 0) {
            mini = 0;
        }
        if (pp < 0) {
            return 0;
        }
        if (ind >= g.size()) {
            if (mini > 0) {
                return 0;
            } else {
                return 1;
            }
        } else if (dp[ind][mini][pp] != -1) {
            return dp[ind][mini][pp];
        }
        // take
        int take = fun(mini - p[ind], ind + 1, pp - g[ind], g, p, dp);
        int ntake = fun(mini, ind + 1, pp, g, p, dp);
        return dp[ind][mini][pp] = (take + ntake)%mod;
    }

public:
    int profitableSchemes(int n, int minp, vector<int>& g, vector<int>& p) {
        int size = g.size();
        vector<vector<vector<int>>> dp(
            size + 1, vector<vector<int>>(minp + 1, vector<int>(n + 1, -1)));
        // vector<vector<int>>dp(g.size(),vector<int>(minp,-1));
        return fun(minp, 0, n, g, p, dp)%mod;
        // return ans%mod;
    }
};