class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0;
        unordered_map<int,int>m;
        int ans=0;
        while(j<n){
            m[nums[j]]++;
            if(m[nums[j]]>k){
                while(i<=j&&m[nums[j]]>k){
                    m[nums[i++]]--;
                }
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};