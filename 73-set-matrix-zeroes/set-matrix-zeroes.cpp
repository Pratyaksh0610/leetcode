class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int columns=matrix[0].size();
        bool isInitialRowZero=false,isInitialColumnZero=false;
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(matrix[i][j]==0){
                    if(i!=0){
                    matrix[i][0]=0;
                    }
                    else{
                        isInitialRowZero=true;
                    }
                    matrix[0][j]=0;
                }
            }
        }
        //matrix done except 1st row and 1st col
        for(int i=1;i<rows;i++){
            for(int j=1;j<columns;j++){
                if(matrix[i][0]==0||matrix[0][j]==0){
                    matrix[i][j]=0;
                }
            }
        }
        //1st col
        if(matrix[0][0]==0){
            for(int i=0;i<rows;i++){
                matrix[i][0]=0;
            }
        }
        //1st row
        if(isInitialRowZero){
            for(int i=0;i<columns;i++){
                matrix[0][i]=0;
            }
        }
        
    }
};