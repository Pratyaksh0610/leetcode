#define ll long long int
class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        ll n=nums.size();
        sort(nums.begin(),nums.end());
        if(n%2==0){
            // k=k*2;
            ll ind1=n/2-1,ind2=n/2;
            ll val=max(nums[ind1],nums[ind2]);
            if(val==k){
                return 0;
            }
            else if(val>k){
                ll it=lower_bound(nums.begin(),nums.end()+ind2,k)-nums.begin();
                ll sum=0,cnt=0;
                while(it<=ind2){
                    sum+=nums[it],cnt++;
                    it++;
                }
                return sum-(k*cnt);
            }
            else if(val<k){
                ll it=ind2;
                ll sum=0,cnt=0;
                while(it<=n-1){
                    if(nums[it]>=k){
                        break;
                    }
                    sum+=nums[it],cnt++;
                    it++;
                }
                return abs(sum-(k*cnt));
            }
            return -1;
        }
        else{
            ll ind=(n+1)/2 -1;
            if(nums[ind]==k){
                return 0;
            }
            else if(nums[ind]<k){
                ll it=ind;
                ll sum=0,cnt=0;
                while(it<=n-1){
                    if(nums[it]>=k){
                        break;
                    }
                    sum+=nums[it],cnt++;
                    it++;
                }
                return abs(sum-(k*cnt));
            }
            else if(nums[ind]>k){
                ll it=lower_bound(nums.begin(),nums.end()+ind,k)-nums.begin();
                ll sum=0,cnt=0;
                while(it<=ind){
                    sum+=nums[it],cnt++;
                    it++;
                }
                return sum-(k*cnt);
            }
        }
        return -1;
    }
};