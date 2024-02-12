class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int size=nums.size();
        int ele=nums[0];
        int cnt=1;
        for(int i=1;i<size;i++){
            if(nums[i]==ele){
                cnt++;
            }
            else{
                if(cnt==0){
                    ele=nums[i];
                    continue;
                }
                cnt--;
            }
        }
        return ele;
    }
};