class Solution {
public:
    int numberOfPairs(vector<vector<int>>& p) {
        // sort(p.begin(),p.end());
        // vector<bool>valid(n,true);
        int n=p.size(),cnt=0;
        for(int i=0;i<n;i++){
            //top left
            int tlx=p[i][0],tly=p[i][1];
            for(int j=0;j<n;j++){
                //bottom right
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
                    // cout<<"POINT"<<endl;
                    // cout<<px<<" "<<py<<endl;
                    // cout<<tlx<<" "<<trx<<endl;
                    // cout<<bly<<" "<<tryy<<endl;
                    if(px>=tlx&&px<=trx&&py>=bly&&py<=tryy){
                        isPossible=false;
                        break;
                    }
                }
                if(isPossible){
                    cnt++;
                    cout<<i<<" "<<j<<" BNGYA";
                }
            }
        }
        return cnt;
    }
};