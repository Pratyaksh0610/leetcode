#define ll long long int

const int mod=1e9+7;

class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        set<int>s;
        ll maxi=0;
        ll ans=0;
        for(int i=0;i<n;i++){
            s.insert(nums1[i]);
        }
        s.insert(-1);
        for(int i=0;i<n;i++){
            auto it=s.lower_bound(nums2[i]);
            int curr=*it;
            int prev=*(--it);
            ll value=abs(nums1[i]-nums2[i]);
            ll mini=(abs(nums2[i]-curr));
            if(prev!=-1){
                mini=min(mini,(ll)abs(nums2[i]-prev));
            }
            ll diff=value-mini;
            if(diff>maxi){
                maxi=diff;
            }
            ans+=value;
        }
        ans-=maxi;
        return ans%mod;
    }
};