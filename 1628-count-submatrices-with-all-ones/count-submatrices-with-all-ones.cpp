class Solution {
public:
    int numSubmat(vector<vector<int>>& m) {
        int r=m.size();
        int c=m[0].size();
        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(m[i][j]==0){
                    continue;
                }
                int rr=i,cc=j;
                int re=r-1,ce=c-1;
                for(;rr<=re;rr++){
                    for(;cc<=ce;cc++){
                        if(m[rr][cc]==1){
                            ans++;
                        }
                        else{
                            ce=cc-1;
                        }
                    }
                    cc=j;
                }
            }
        }
        return ans;
    }
};