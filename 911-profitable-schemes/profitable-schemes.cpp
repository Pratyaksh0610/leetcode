#define ll long long int
const int mod = 1e9 + 7;
class Solution {
private:
    ll ans = 0;
    ll fun(ll mini, ll ind, ll pp, vector<int>& g, vector<int>& p,
            vector<vector<vector<ll>>>& dp) {
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
        ll take = fun(mini - p[ind], ind + 1, pp - g[ind], g, p, dp);
        ll ntake = fun(mini, ind + 1, pp, g, p, dp);
        return dp[ind][mini][pp] = (take + ntake)%mod;
    }

public:
    int profitableSchemes(ll n, ll minp, vector<int>& g, vector<int>& p) {
        ll size = g.size();
        vector<vector<vector<ll>>> dp(
            size + 1, vector<vector<ll>>(minp + 1, vector<ll>(n + 1, -1)));
        // vector<vector<int>>dp(g.size(),vector<int>(minp,-1));
        return fun(minp, 0, n, g, p, dp)%mod;
        // return ans%mod;
    }
};