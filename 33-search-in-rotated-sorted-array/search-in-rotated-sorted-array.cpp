class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int si = 0, ei = n - 1;
        while (si <= ei) {
            int mid = si + (ei - si) / 2;
            if (target == nums[mid]) {
                return mid;
            }
            if (nums[si] <= nums[mid]) {
                if (target>=nums[si] && target<nums[mid]) {
                    ei = mid - 1;
                }
                else{
                    si=mid+1;
                }
            } else if (nums[mid] <= nums[ei]) {
                if (target>nums[mid] && target<=nums[ei]) {
                    si = mid + 1;
                }
                else{
                    ei=mid-1;
                }
            }
        }
        return -1;
    }
};