class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0;i<n;i++){
            if(i!=0){
                while(i<n&&nums[i-1]==nums[i]){
                    i++;
                }
                if(i>=n) break;
            }
            int st=i+1,end=n-1,rem=-nums[i];
            while(st<end){
                int sum=nums[st]+nums[end];
                if(sum>rem){
                    end--;
                }
                else if(sum<rem){
                    st++;
                }
                else{
                    vector<int>ans2={nums[i],nums[st],nums[end]};
                    ans.push_back(ans2);
                    st++;
                    end--;
                    while(st<end&&nums[st]==nums[st-1]){
                        st++;
                    }
                    while(st<end&&nums[end]==nums[end+1]){
                        end--;
                    }
                }
            }
        }
        return ans;
    }
};