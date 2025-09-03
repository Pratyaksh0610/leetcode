class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int cnt=0;
        int ind=-1;
        for(int i=0;i<n;i++){
            if(cnt==0){
                cnt=1;
                ind=i;
            }
            else if(cnt>0){
                if(nums[i]==nums[ind]) cnt++;
                else cnt--;
            }
        }
        return nums[ind];
    }
};