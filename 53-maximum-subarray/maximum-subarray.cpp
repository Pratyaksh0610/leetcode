class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN;
        int curr=0;
        for(int i=0;i<n;i++){
            curr+=nums[i];
            maxi=max(maxi,curr);
            if(curr<0)curr=0;
        }
        return maxi;
    }
};