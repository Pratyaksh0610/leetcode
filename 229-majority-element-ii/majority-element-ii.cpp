class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int el1=INT_MIN,el2=INT_MIN;
        int c1=0,c2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==el1){
                c1++;
            }
            else if(nums[i]==el2){
                c2++;
            }
            else if(el1==INT_MIN){
                el1=nums[i];
                c1=1;
            }
            else if(el2==INT_MIN){
                el2=nums[i];
                c2=1;
            }
            else{
                // c1--;
                // c2--;
                if(c1==0){
                    el1=nums[i];
                    c1=1;
                }
                else if(c2==0){
                    el2=nums[i];
                    c2=1;
                }
                else{
                    c1--;
                    c2--;
                }
            }
        }
        c1=0,c2=0;
        for(int i=0;i<n;i++){
            if(nums[i]==el1){
                c1++;
            }
            else if(nums[i]==el2){
                c2++;
            }
        }
        vector<int>ans;
        if(c1>n/3){
            ans.push_back(el1);
        }
        if(c2>n/3){
            ans.push_back(el2);
        }
        return ans;
    }
};