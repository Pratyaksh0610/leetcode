#define ll long long int

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& p) {
        ll np = p.size();
        vector<int> ind(np, 0);
        vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            ll mini = INT_MAX;
            for (int j = 0; j < np; j++) {
                ll val = (ll)dp[ind[j]] * (ll)p[j];
                mini = min(mini, val);
            }
            for (int j = 0; j < np; j++) {
                ll val = (ll)dp[ind[j]] * (ll)p[j];

                if (val == mini) {
                    ind[j]++;
                }
            }
            dp[i] = mini;
        }
        return dp[n - 1];
    }
};