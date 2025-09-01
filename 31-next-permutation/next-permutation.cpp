class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();//3
        int index=n-1;//2
        //1,2,3
        for(int i=n-2;i>=0;i--){//1
            if(nums[i]<nums[i+1]){
                index=i;//1
                break;
            }
        }
        int bIndex=-1;
        for(int i=index+1;i<n;i++){//1
            if(nums[i]>nums[index]&&bIndex!=-1&&nums[bIndex]>nums[index]){
                bIndex=i;
            }
            if(bIndex==-1){
                bIndex=i;
            }
        }
        if(bIndex==-1){
            sort(nums.begin(),nums.end());
            return;
        }
        swap(nums[bIndex],nums[index]);
        // cout<<index<<endl;
        sort(nums.begin()+index+1,nums.end());
    }
};