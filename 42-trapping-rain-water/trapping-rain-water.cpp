class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size();
        // stack<int>st;
        vector<int>nge(n,n),pge(n,-1);
        int ans=0;
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
            // while(st.size()&&h[st.top()]<h[i]){
            //     int ind=st.top();
            //     st.pop();
            //     nge[ind]=i;
            // }
            // st.push(i);
            maxi=max(maxi,h[i]);
            nge[i]=maxi;
        }
        maxi=INT_MIN;
        // while(st.size()) st.pop();
        for(int i=n-1;i>=0;i--){
            // while(st.size()&&h[st.top()]<h[i]){
            //     int ind=st.top();
            //     st.pop();
            //     pge[ind]=i;
            // }
            // // if(st.size(
            // st.push(i);
            maxi=max(maxi,h[i]);
            pge[i]=maxi;
        }
        // for(auto it:nge){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        //  for(auto it:pge){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        for(int i=0;i<n;i++){
            // if(nge[i]==n||pge[i]==-1){
            //     continue;
            // }
            int add=min(nge[i],pge[i])-h[i];
            // cout<<i<<" "<<add<<endl;
            ans+=add;
        }
        return ans;
    }
};