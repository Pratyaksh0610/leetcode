class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        //sum of 2 sides>3rd side
        //1,1,2,3,4,5,7,9,13,25
        sort(nums.begin(),nums.end());
        int n=nums.size(),ans=0;
        for(int k=n-1;k>=2;k--){
            int i=0,j=k-1;
            while(i<j){
                int val=nums[i]+nums[j];
                if(val>nums[k]){
                    ans+=(j-i);
                    j--;
                }
                else{
                    i++;
                }
            }
        }
        return ans;
    }
};