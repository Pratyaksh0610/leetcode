class Solution {
    private:
    bool diagCheck(vector<vector<char>>&v,int r,int c,int &nn){
        int rowInd[]={1,-1,1,-1};
        int colInd[]={1,-1,-1,1};

        for(int i=0;i<4;i++){
            int rind=r,cind=c;
            while(rind>=0&&rind<nn&&cind>=0&&cind<nn){
                if(v[rind][cind]=='Q'){
                    return false;
                }
                rind+=rowInd[i];
                cind+=colInd[i];
            }
        }
        return true;
    }
    bool straightCheck(vector<vector<char>>&v,int r,int c,int &nn){
        int rowInd[]={0,0,1,-1};
        int colInd[]={1,-1,0,0};

        for(int i=0;i<4;i++){
            int rind=r,cind=c;
            while(rind>=0&&rind<nn&&cind>=0&&cind<nn){
                if(v[rind][cind]=='Q'){
                    return false;
                }
                rind+=rowInd[i];
                cind+=colInd[i];
            }
        }
        return true;
    }
    void fun(vector<vector<string>>&ans,vector<vector<char>>&v,int r,int n,int &nn){
        if(n==0){
            vector<string>fans;
            for(int i=0;i<nn;i++){
                string temp;
                for(int j=0;j<nn;j++){
                    temp+=v[i][j];
                }
                fans.push_back(temp);
            }
            ans.push_back(fans);
            return;
        }
        for(int c=0;c<nn;c++){
            bool isPossible = diagCheck(v,r,c,nn) & straightCheck(v,r,c,nn);
            if(isPossible){
                v[r][c]='Q';
                fun(ans,v,r+1,n-1,nn);
                v[r][c]='.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<vector<char>>v(n,vector<char>(n,'.'));
        fun(ans,v,0,n,n);
        return ans;
    }
};