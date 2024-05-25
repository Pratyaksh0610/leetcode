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
                unordered_map<ll,int>m;
                for(int k=j+1;k<n;k++){
                    ll tot=sum+nums[k];
                    ll rem=t-tot;
                    if(m.find(rem)!=m.end()){
                        vector<int>temp={nums[i],nums[j],nums[k],(int)rem};
                        ans.push_back(temp);
                        int value=nums[k];
                        while(k<n&&nums[k]==value){
                            k++;
                        }
                        if(k<n){
                            k--;
                        }
                        // s.insert(temp);
                    }
                    if(k<n){
                        m[nums[k]]++;
                    }
                    // m[nums[k]]++;
                }
            }
        }
        // for(auto it:s){
        //     ans.push_back(it);
        // }
        return ans;
    }
};