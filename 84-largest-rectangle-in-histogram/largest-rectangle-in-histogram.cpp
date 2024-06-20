class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n=h.size();
        stack<int>st;
        vector<int>l(n,0),r(n,0);
        int ans=0;
        for(int i=0;i<n;i++){
            while(st.size()&&h[i]<=h[st.top()]){
                st.pop();
            }
            if(st.size()){
                l[i]=h[i]*(i-st.top());
            }
            else{
                l[i]=max(ans,(i+1)*h[i]);
            }
            st.push(i);
        }
        while(st.size()){
            st.pop();
        }
        for(int i=n-1;i>=0;i--){
            while(st.size()&&h[i]<=h[st.top()]){
                st.pop();
            }
            if(st.size()){
                r[i]=h[i]*(st.top()-i);
            }
            else{
                r[i]=max(ans,(n-i)*h[i]);
            }
            st.push(i);
        }
        for(int i=0;i<n;i++){
            // cout<<l[i]<<" "<<r[i]<<endl;
            ans=max(l[i]+r[i]-h[i],ans);
        }
        return ans;
    }
};