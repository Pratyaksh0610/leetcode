class Solution {
public:
    int trap(vector<int>& height) {
        int ans=0;
        int n=height.size();
        vector<int>prefL(n,0),prefR(n,0);
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,height[i]);
            prefL[i]=maxi;
        }
        maxi=0;
        for(int i=n-1;i>=0;i--){
            maxi=max(maxi,height[i]);
            prefR[i]=maxi;
        }
        for(int i=1;i<n-1;i++){
            ans+=max(min(prefL[i-1],prefR[i+1])-height[i],0);
        }
        return ans;
    }
};