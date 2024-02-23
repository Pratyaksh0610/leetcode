class Solution {
    private:
    bool fun(int mid,vector<int>&nums,int k){
        int yet=0;
        int i=0;
        while(i<nums.size()){
            if(nums[i]<=mid){
                i+=2;
                yet++;
            }
            else{
                i++;
            }
            if(yet>=k){
                return true;
            }
        }
        return false;
    }
public:
    int minCapability(vector<int>& nums, int k) {
        int si=1,ei=1e9;
        int ans=0;
        while(si<=ei){
            int mid=si+(ei-si)/2;
            bool check=fun(mid,nums,k);
            if(check){
                ans=mid;
                ei=mid-1;
            }
            else{
                si=mid+1;
            }
        }
        return ans;
    }
};