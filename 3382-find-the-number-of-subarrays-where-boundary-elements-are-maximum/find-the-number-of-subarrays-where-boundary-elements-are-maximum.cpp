#define ll long long int

class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        ll ans=0;
        stack<int>st;
        int n=nums.size();
        vector<int>nge(n,-1);
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            while(st.size()&&nums[st.top()]<=nums[i]){
                nge[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        // for(int i=0;i<n;i++){
        //     cout<<nge[i]<<" ";
        // }
        for(int i=0;i<n;i++){
            if(vis[i]){
                continue;
            }
            vis[i]=true;
            ll ele=nums[i];
            int next=nge[i];
            ll a=1;
            ll cnt=2;
            int j=next;
            while(j!=-1&&nums[j]==ele){
                vis[j]=true;
                a+=cnt++;
                j=nge[j];
            }
            ans+=a;
        }
        return ans;
    }
};