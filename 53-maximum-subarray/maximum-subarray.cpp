class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxi=nums[0];
        int i=0,j=1;
        int sum=nums[0];
        while(j<n){
            while(sum<0&&i<j){
                sum-=nums[i++];
            }
            sum+=nums[j++];
            // j++;
            maxi=max(sum,maxi);
        }
        return maxi;
    }
};