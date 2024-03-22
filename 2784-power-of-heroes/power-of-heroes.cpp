#define ll unsigned long long int
const int mod = 1e9 + 7;
class Solution {
public:
    int sumOfPower(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        ll pp = (ll)(powl(nums[n - 1], 2)) % mod;
        ll ans = (pp * nums[n - 1]) % mod;
        ll sum = (ll)powl(nums[n - 1], 2) % mod;
        for (int i = n - 2; i >= 0; i--) {
            ll psum = sum%mod;
            ll nsum =(( sum%mod )+( (ll)powl(nums[i], 2)%mod))%mod;
            ans =(ans+( (nums[i] * (nsum % mod)) % mod))%mod;
            ans = ans % mod;
            sum = (psum%mod + nsum%mod)%mod;
        }
        return ans%mod;
    }
};