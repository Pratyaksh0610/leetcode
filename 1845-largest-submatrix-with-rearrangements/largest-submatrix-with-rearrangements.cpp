class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& m) {
        int r=m.size(),c=m[0].size();
        for(int i=0;i<c;i++){
            for(int j=0;j<r;j++){
                if(j!=0&&m[j][i]==1){
                    m[j][i]+=m[j-1][i];
                }
            }
        }
        int ans=0;
        for(int i=0;i<r;i++){
            priority_queue<int>pq;
            for(int j=0;j<c;j++){
                pq.push(m[i][j]);
            }
            // cout<<endl;
            while(pq.size()){
                int mini=pq.top();
                pq.pop();
                int cnt=c-pq.size();
                ans=max(ans,cnt*mini);
            }
        }
        return ans;
    }
};