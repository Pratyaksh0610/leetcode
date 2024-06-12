class Solution {
public:
    void sortColors(vector<int>& nums) {
        //2,0,2,1,1,0
        int n = nums.size();
        int i = 0, j = n - 1;
        int k=0;
        while(k<=j){
            if(nums[k]==0){
                swap(nums[k],nums[i]);
                k++;
                i++;
            }
            else if(nums[k]==2){
                swap(nums[j],nums[k]);
                j--;
            }
            else{
                k++;
            }
        }
    }
};