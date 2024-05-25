#define ll long long int

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, ll t) {
        ll n=nums.size();
        vector<vector<int>>ans;
        // set<vector<int>>s;
        sort(nums.begin(),nums.end());

        for(int i=0;i<n;i++){
            if(i!=0&&nums[i]==nums[i-1]){
                continue;
            }
            for(int j=i+1;j<n;j++){
                if(j!=i+1&&nums[j]==nums[j-1]){
                    continue;
                }
                ll sum=nums[i]+nums[j];
                int k=j+1,l=n-1;
                while(k<l){
                    ll val=sum+nums[k]+nums[l];
                    if(val==t){
                        vector<int>temp={nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(temp);
                        int kk=nums[k];
                        while(k<l&&nums[k]==kk){
                            k++;
                        }
                    }
                    else if(val>t){
                        l--;
                    }
                    else if(val<t){
                        k++;
                    }
                }
            }
        }
        // for(auto it:s){
        //     ans.push_back(it);
        // }
        return ans;
    }
};