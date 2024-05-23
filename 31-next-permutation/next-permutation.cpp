class Solution {
public:
// 1,3,2 should be 2,1,3
//1,3,2,0 should be 2,0,1,3
//1,5,1
//  i
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int i=n-2;
        for(;i>=0;i--){
            if(nums[i]<nums[i+1]){
                break;
            }
        }
        cout<<i<<endl;
        if(i==-1){
            reverse(nums.begin(),nums.end());
            return;
        }
        int smallest=nums[i];
        for(int j=n-1;j>=i;j--){
            if(nums[j]>nums[i]){
                swap(nums[i],nums[j]);
                break;
            }
        }
        reverse(nums.begin()+i+1,nums.end());
    }
};