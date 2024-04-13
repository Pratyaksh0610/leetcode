class Solution {
    private:
        int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>lmin;
        vector<int>l(n,0);
        vector<int>r(n,0);
        for(int i=0;i<n;i++){

            while(lmin.size()&&heights[lmin.top()]>heights[i]){
                l[lmin.top()]=i-1;
                lmin.pop();
            }
            lmin.push(i);
        }
        
        while(lmin.size()){
            l[lmin.top()]=n-1;
            lmin.pop();
        }

        for(int i=n-1;i>=0;i--){
            while(lmin.size()&&heights[lmin.top()]>heights[i]){
            r[lmin.top()]=i+1;
            lmin.pop();
        }
            lmin.push(i);
        }
        while(lmin.size()){
            r[lmin.top()]=0;
            lmin.pop();
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            int c=l[i]-r[i]+1;
            c*=heights[i];
            maxi=max(maxi,c);
        }
        return maxi;

    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        vector<int>h;
        for(int i=0;i<c;i++){
            h.push_back(matrix[0][i]-'0');
        }

        int ans=largestRectangleArea(h);
        
        for(int i=1;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]!='0'){
                    h[j]+=matrix[i][j]-'0';
                }
                else{
                    h[j]=0;
                }
            }
            int curr=largestRectangleArea(h);
            ans=max(curr,ans);
        }
        return ans;
    }
};