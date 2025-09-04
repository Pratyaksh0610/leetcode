class Solution {
    //
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        int n=nums.size();
        int limit=n/3;
        int n1=nums[0],n2=INT_MIN;
        int cnt1=1,cnt2=0;
        for(int i=1;i<n;i++){
            if(nums[i]==n1){
                cnt1++;
            }
            else if(nums[i]==n2){
                cnt2++;
            }
            else if(cnt1==0){
                n1=nums[i];
                cnt1=1;
            }
            else if(cnt2==0){
                n2=nums[i];
                cnt2=1;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1=0,cnt2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==n1) cnt1++;
            if(nums[i]==n2) cnt2++;
        }
        if(cnt1>limit){
            ans.push_back(n1);
        }
        if(cnt2>limit){
            ans.push_back(n2);
        }
        return ans;
    }
};