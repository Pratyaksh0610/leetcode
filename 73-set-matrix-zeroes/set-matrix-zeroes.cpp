class Solution {
public:
    void setZeroes(vector<vector<int>>& m) {
        int r=m.size(),c=m[0].size();

        bool rowz=false,colz=false;
        for(int j=0;j<c;j++){
            if(m[0][j]==0){
                rowz=true;
            }
        }
        for(int i=0;i<r;i++){
            if(m[i][0]==0){
                colz=true;
            }
        }
        for(int i=1;i<r;i++){
            for(int j=1;j<c;j++){
                if(m[i][j]==0){
                    m[0][j]=0;
                    m[i][0]=0;
                }
            }
        }
        for(int i=1;i<r;i++){
            if(m[i][0]==0){
                for(int j=0;j<c;j++){
                    m[i][j]=0;
                }
            }
        }
        for(int j=1;j<c;j++){
            if(m[0][j]==0){
                for(int i=0;i<r;i++){
                    m[i][j]=0;
                }
            }
        }
        if(rowz){
            for(int j=0;j<c;j++){
                m[0][j]=0;
            }
        }
        if(colz){
            for(int i=0;i<r;i++){
                m[i][0]=0;
            }
        }
    }
};