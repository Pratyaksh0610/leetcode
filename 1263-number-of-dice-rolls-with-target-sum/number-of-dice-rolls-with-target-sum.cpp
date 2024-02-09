#define ll long long int
class Solution {
private:
    const int mod = 1e9 + 7;
    int fun(int n, int k, int t, vector<vector<ll>>& dp) {
        if (t == 0&&n==0) {
            return dp[n][t] = 1;
        }
        else if(t==0){
            return dp[n][t]= 0;
        }
        if (n == 0) {
            return dp[n][t] = 0;
        } else if (dp[n][t] != -1) {
            return dp[n][t] % mod;
        }
        ll ans = 0;
        for (int i = 1; i <= min(k, t); i++) {
            ll val = fun(n - 1, k, t - i, dp);
            val = val % mod;
            ans += val;
            ans = ans % mod;
        }
        return dp[n][t] = ans % mod;
    }

public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<ll>> dp(n + 1, vector<ll>(target + 1, -1));
        return fun(n, k, target, dp) % mod;
    }
};