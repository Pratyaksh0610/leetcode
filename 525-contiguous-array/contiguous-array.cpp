class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>m;
        m[0]=-1;
        int sum=0,ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                sum-=1;
            }
            else{
                sum+=1;
            }
            if(m.find(sum)==m.end()){
                m[sum]=i;
            }
            else{
                ans=max(ans,i-m[sum]);
            }
        }
        return ans;
    }
};