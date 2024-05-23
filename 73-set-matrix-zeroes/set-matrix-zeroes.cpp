class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        int r=m.size(),c=m[0].size();
        vector<bool>prow(r,false),pcol(c,false);
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(m[i][j]==0){
                    prow[i]=true;
                    pcol[j]=true;
                }
            }
        }
        for(int i=0;i<r;i++){
            if(prow[i]){
                for(int j=0;j<c;j++){
                    m[i][j]=0;
                }
            }
        }
        for(int j=0;j<c;j++){
            if(pcol[j]){
                for(int i=0;i<r;i++){
                    m[i][j]=0;
                }
            }
        }
        
    }
};