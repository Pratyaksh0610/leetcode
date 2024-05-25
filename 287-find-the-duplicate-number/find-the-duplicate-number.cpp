class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int slow=nums[0],fast=nums[0];
        int start=nums[0];
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        }while(slow!=fast);
        
        while(start!=slow){
            start=nums[start];
            slow=nums[slow];
        }
        return slow;
    }
};