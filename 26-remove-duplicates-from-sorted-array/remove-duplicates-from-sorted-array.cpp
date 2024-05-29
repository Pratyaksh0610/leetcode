class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>m;
        int i=0,j=0;
        while(j<n){
            if(m.find(nums[j])==m.end()){
                nums[i++]=nums[j];
                m[nums[j]]++;
            }
            j++;
        }
        return i;
    }
};