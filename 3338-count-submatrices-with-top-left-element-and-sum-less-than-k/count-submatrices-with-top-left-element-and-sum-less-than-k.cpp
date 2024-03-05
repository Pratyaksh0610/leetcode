class Solution {
public:
    int countSubmatrices(vector<vector<int>>& g, int k) {
        int r=g.size(),c=g[0].size(),ans=0;
        for(int i=0;i<r;i++){
            int sum=0;
            for(int j=0;j<c;j++){
                sum+=g[i][j];
                g[i][j]=sum;
                if(i!=0){
                    g[i][j]+=g[i-1][j];
                }
                if(g[i][j]<=k){
                    ans++;
                }
            }
        }
        return ans;
    }
};