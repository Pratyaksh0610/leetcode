class Solution {
public:
    int numberOfPairs(vector<vector<int>>& p) {
        int n=p.size(),cnt=0;
        for(int i=0;i<n;i++){
            int tlx=p[i][0],tly=p[i][1];
            for(int j=0;j<n;j++){
                int brx=p[j][0],bry=p[j][1];
                if(tlx>brx||tly<bry||i==j){
                    continue;
                }
                bool isPossible=true;
                int trx=brx,tryy=tly;
                int blx=tlx,bly=bry;
                for(int k=0;k<n;k++){
                    if(k==i||k==j){
                        continue;
                    }
                    int px=p[k][0],py=p[k][1];
                    if(px>=tlx&&px<=trx&&py>=bly&&py<=tryy){
                        isPossible=false;
                        break;
                    }
                }
                if(isPossible){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};