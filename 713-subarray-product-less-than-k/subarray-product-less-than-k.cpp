#define ll long long int
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0 || k == 1) {
            return 0;
        }
        ll p = 1;
        int n = nums.size(), i = 0, j = 0;
        int ans = 0;
        while (j < n) {
            p *= nums[j++];
            while (p >= k && i < j) {
                p /= nums[i++];
            }
            if (i != j) {
                ans += j - i;
            }
        }
            return ans;
    }
};