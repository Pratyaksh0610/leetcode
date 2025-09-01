class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int columns=matrix[0].size();
        vector<bool>zeroRows(rows,false),zeroColumns(columns,false);
        for(int i=0;i<rows;i++){
            for(int j=0;j<columns;j++){
                if(matrix[i][j]==0){
                    zeroRows[i]=true;
                    zeroColumns[j]=true;
                }
            }
        }
        for(int i=0;i<rows;i++){
            if(zeroRows[i]){
                for(int j=0;j<columns;j++){
                    matrix[i][j]=0;
                }
            }
        }
        for(int i=0;i<rows;i++){
            if(zeroRows[i]){
                for(int j=0;j<columns;j++){
                    matrix[i][j]=0;
                }
            }
        }for(int i=0;i<columns;i++){
            if(zeroColumns[i]){
                for(int j=0;j<rows;j++){
                    matrix[j][i]=0;
                }
            }
        }
    }
};