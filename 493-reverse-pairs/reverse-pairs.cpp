#define ll long long int
class Solution {
    private:

    void merge(vector<int>&nums,int si,int ei,int &ans){
        if(si>=ei) return;
        int mid=si+(ei-si)/2;
        int index=mid+1;
        for(int i=si;i<=mid;i++){
            // while(index<=ei && nums[i]>(ll)2*nums[index]){
            //     index++;
            // }
            int st=index,end=ei;
            while(st<=end){
                int mm=st+(end-st)/2;
                if(nums[i]>(ll)2*nums[mm]){
                    st=mm+1;
                    index=max(index,st);
                }
                else{
                    end=mm-1;
                }
            }
            ans+=index-(mid+1);
        }
        vector<int>temp;
        int i=si,j=mid+1;
        while(i<=mid&&j<=ei){
            if(nums[i]<nums[j]){
                temp.push_back(nums[i++]);
            }
            else{
                temp.push_back(nums[j++]);
            }
        }
        while(i<=mid){
            temp.push_back(nums[i++]);
        }
        while(j<=ei){
            temp.push_back(nums[j++]);
        }
        for(int k=si;k<=ei;k++){
            nums[k]=temp[k-si];
        }
        return;
    }

    void split(vector<int>&nums,int si,int ei,int &ans){
        if(si>=ei) return;
        int mid=si+(ei-si)/2;
        split(nums,si,mid,ans);
        split(nums,mid+1,ei,ans);
        merge(nums,si,ei,ans);
        return;
    }
public:
    int reversePairs(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        split(nums,0,n-1,ans);
        return ans;
    }
};