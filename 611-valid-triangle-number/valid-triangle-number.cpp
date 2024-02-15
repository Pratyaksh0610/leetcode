class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        //sum of 2 sides>3rd side
        //1,1,2,3,4,5,7,9,13,25
        sort(nums.begin(),nums.end());
        int n=nums.size(),ans=0;
        for(int i=2;i<n;i++){
            for(int j=0;j<i-1;j++){
                int si=j+1,ei=i-1,ind=-1;
                while(si<=ei){
                    int mid=si+(ei-si)/2;
                    if(nums[mid]+nums[j]>nums[i]){
                        ind=mid;
                        ei=mid-1;
                    }
                    else{
                        si=mid+1;
                    }
                }
                if(ind!=-1){
                    ans+=(i-ind);
                }
            }
        }
        return ans;
    }
};