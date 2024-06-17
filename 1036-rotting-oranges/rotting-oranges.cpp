#define pi pair<int,int>

class Solution {
public:
    int orangesRotting(vector<vector<int>>& g) {
        queue<pi>q;
        int r=g.size(),c=g[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(g[i][j]==2){
                    q.push({i,j});
                }
            }
        }
        int time=0;
        int row[]={-1,1};
        int col[]={1,-1};
        while(q.size()){
            // time++;
            bool done=true;
            int s=q.size();
            while(s>0){
                pi temp=q.front();
                q.pop();
                s--;
                int i=temp.first,j=temp.second;
                if(i<0||i>=r||j<0||j>=c||g[i][j]==0){
                    continue;
                }
                else{
                    g[i][j]=0;
                    // cout<<i<<" "<<j<<endl;
                    done=false;
                    q.push({i+0,j+1});
                    q.push({i+1,j});
                    q.push({i-1,j});
                    q.push({i,j-1});
                }
            }
            if(!done){
                time++;
            }
        }
        for(auto it:g){
            for(auto it2:it){
                // cout<<it2<<" ";
                if(it2==1){
                    return -1;
                }
            }
            // cout<<endl;
        }
        return max(time-1,0);
    }
};