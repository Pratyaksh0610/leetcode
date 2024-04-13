#define pi pair<int,int>

class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& dis) {
        vector<int>vis(n,-1);
        //-1,-1,-1
        priority_queue<pi,vector<pi>,greater<pi>>pq;
        vector<vector<pi>>e(n);
        for(int i=0;i<edges.size();i++){
            int f=edges[i][0],s=edges[i][1],c=edges[i][2];
            e[f].push_back({s,c});
            e[s].push_back({f,c});
        }
        
        pq.push({0,0});
        //{time,node}
        while(pq.size()){
            pi temp=pq.top();
            pq.pop();

            int node=temp.second;
            int time=temp.first;

            if(vis[node]!=-1||dis[node]<=time){
                continue;
            }
            else{
                vis[node]=time;
                for(int i=0;i<e[node].size();i++){
                    pi temp=e[node][i];
                    int cost1=temp.second;
                    int node1=temp.first;
                    if(vis[node1]==-1){
                        pq.push({time+cost1,node1});
                    }
                }
            }
        }
        return vis;
    }
};