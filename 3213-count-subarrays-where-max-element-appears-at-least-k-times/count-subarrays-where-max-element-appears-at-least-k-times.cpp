#define ll long long int
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=-1;
        ll ans=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
        }
        int i=0,j=0;
        unordered_map<int,int>m;
        while(j<n){
            m[nums[j]]++;
            while(m[maxi]>=k){
                m[nums[i]]--;
                ans+=(n-j);
                i++;
            }
            j++;
        }
        return ans;
    }
};