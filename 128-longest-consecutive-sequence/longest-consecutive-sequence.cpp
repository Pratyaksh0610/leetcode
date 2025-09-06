#define ll long long int
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>m;
        int ans=0;
        int n=nums.size();
        // vector<int>v(n,0);
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        for(auto it:m){
            int val=it.first;
            int freq=it.second;
            // cout<<val<<" "<<freq<<endl;
            if(m.find(val-1)!=m.end()){
                continue;
            }
            else{
                int cnt=0;
                int inc=0;
                while(m.find(val+inc)!=m.end()){
                    // val++;
                    cnt++;
                    inc++;
                }
                ans=max(ans,cnt);
            }
        }
        return ans;
    }
};