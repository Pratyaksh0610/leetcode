class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int slow=nums[0];
        int fast=nums[0];
        while(true){
            slow=nums[slow];
            fast=nums[nums[fast]];
            if(slow==fast){
                break;
            }
        }
        fast=nums[0];
        while(true){
            if(fast==slow){
                return fast;
            }
            fast=nums[fast];
            slow=nums[slow];
        }
        return -1;
    }
};