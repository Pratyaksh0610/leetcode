#define ll long long int
class Solution {
    void inc(vector<int>& bits, int val, ll &orr) {
        orr = orr | val;
        for (int i = 0; i < 32; i++) {
            if ((val >> i) % 2 != 0) {
                bits[i]++;
            }
        }
        return;
    }
    void dec(vector<int>& bits, int val, ll &orr) {
        // or = or | val;
        for (int i = 0; i < 32; i++) {
            if ((val >> i) % 2 != 0) {
                bits[i]--;
                if (bits[i] == 0) {
                    orr = orr &(~(1 << i));
                }
            }
        }
        return;
    }

public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int> bits(32, 0);
        int i = 0, j = 0, n = nums.size();
        ll orr = 0;
        int ans=INT_MAX;
        while (j < n) {
            inc(bits, nums[j], orr);
            while(orr>=k&&i<=j){
                ans=min(ans,j-i+1);
                dec(bits,nums[i++],orr);
            }
            j++;
        }
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};