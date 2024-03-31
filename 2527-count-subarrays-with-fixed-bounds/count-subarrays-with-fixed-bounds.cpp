#define ll long long int
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int mini, int maxi) {
        int ini=-1,n=nums.size();
        ll ans=0;
        unordered_map<int,int>m;
        for(int i=0;i<n;i++){
            if(nums[i]>maxi||nums[i]<mini){
                ini=i;
                m.erase(maxi);
                m.erase(mini);
            }
            else{
                m[nums[i]]=i;
                if(m.find(maxi)==m.end()||m.find(mini)==m.end()){
                    continue;
                }
                int val=min(m[maxi],m[mini]);
                ans+=val-ini;
            }
        }
        return ans;
    }
};