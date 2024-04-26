#define pi pair<int,int>

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& g) {
        int r=g.size(),c=g[0].size();
        priority_queue<pi>pq;
        //bade se chota

        for(int j=0;j<c;j++){
            pq.push({g[r-1][j],j});
            if(pq.size()>2){
                pq.pop();
            }
        }
        for(int i=r-2;i>=0;i--){
            //bigger
            pi m1=pq.top();
            pq.pop();

            //smaller
            pi m2=pq.top();
            pq.pop();

            for(int j=0;j<c;j++){
                if(j!=m2.second){
                    pq.push({g[i][j]+m2.first,j});
                }
                else{
                    pq.push({g[i][j]+m1.first,j});
                }
                if(pq.size()>2){
                    pq.pop();
                }
            }
        }
        pq.pop();
        return pq.top().first;
    }
};