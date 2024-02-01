class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans,temp;
        if(nums.size()%3!=0){
            return ans;
        }
        int i=0,j=1,k1=2;
        while(k1<nums.size()){
            int d1=abs(nums[i]-nums[k1]);
            int d2=abs(nums[i]-nums[j]);
            int d3=abs(nums[j]-nums[k1]);
            if(d1>k||d2>k||d3>k){
                return temp;
            }
            vector<int>t;
            t.push_back(nums[i]);
            t.push_back(nums[j]);
            t.push_back(nums[k1]);
            ans.push_back(t);
            i=i+3,j=j+3,k1=k1+3;
        }
        return ans;
    }
};