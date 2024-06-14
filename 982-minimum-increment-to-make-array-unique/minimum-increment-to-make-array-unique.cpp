class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        //1,1,2,2,3,7
        //1,2,
        int mini=INT_MIN;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(mini<nums[i]){
                mini=nums[i];
            }
            else if(mini==nums[i]){
                mini=nums[i]+1;
                ans++;
            }
            else if(mini>nums[i]){
                ans+=mini+1-nums[i];
                mini++;
            }
        }
        return ans;
    }
};