class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        int si=0,ei=n-1;
        while(si<=ei){
            int mid=si+(ei-si)/2;
            int left=mid,right=ei-(mid);
            if(mid>0&&mid<n-1){
                if(nums[mid]==nums[mid+1]){
                    right++;
                }
                else if(nums[mid]==nums[mid-1]){
                    left++;
                }
                else{
                    return nums[mid];
                }
            }
            else if(mid==0){
                if(nums[mid]==nums[mid+1]){
                    right++;
                }
                else{
                    return nums[mid];
                }
            }
            else if(mid==n-1){
                if(nums[mid]==nums[mid-1]){
                    left++;
                }
                else{
                    return nums[mid];
                }
            }
            if(left%2==0){
                si=mid+1;
            }
            else{
                ei=mid-1;
            }
        }
        return -1;
    }
};