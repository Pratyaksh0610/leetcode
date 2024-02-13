#define ll long long int
class Solution {
    private:
    bool fun(vector<int>& nums, ll m,ll val){
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=val){
                continue;
            }
            else{
                ll req=nums[i]/val;
                if(nums[i]%val!=0){
                    req++;
                }
                req--;
                m-=req;
            }
            if(m<0){
                return false;
            }
        }
        return true;
    }
public:
    int minimumSize(vector<int>& nums, int m) {
        int n=nums.size();
        ll si=1,ei=1e9;
        ll ans=1;
        while(si<=ei){
            ll mid=si+(ei-si)/2;
            bool ch=fun(nums,m,mid);
            if(ch){
                ans=mid;
                ei=mid-1;
            }
            else{
                si=mid+1;
            }
        }
        return ans;
    }
};