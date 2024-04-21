#define pi pair<int,int>

class Solution {
    private:

    void fun(vector<int>&vis,int node,vector<vector<pi>>&e){
        priority_queue<pi,vector<pi>,greater<pi>>pq;
        pq.push({0,node});
        //dist,node
        while(pq.size()){
            pi temp=pq.top();
            pq.pop();
            int tempNode=temp.second,dist=temp.first;
            if(vis[tempNode]<dist){
                continue;
            }
            vis[tempNode]=dist;
            for(int i=0;i<e[tempNode].size();i++){
                pi it=e[tempNode][i];
                pq.push({dist+it.second,it.first});
            }
        }
    }


public:
    vector<bool> findAnswer(int n, vector<vector<int>>& e) {
        vector<int>vis1(n,1e8),vis2(n,1e8);
        vis1[0]=0,vis2[n-1]=0;
        vector<vector<pi>>edges(n);

        for(int i=0;i<e.size();i++){
            int f=e[i][0],s=e[i][1],w=e[i][2];
            edges[f].push_back({s,w});
            edges[s].push_back({f,w});
        }

        fun(vis1,0,edges);
        fun(vis2,n-1,edges);
        // for(int i=0;i<n;i++){
        //     cout<<vis1[i]<<" ";
        // }
        // cout<<endl;
        // for(int i=0;i<n;i++){
        //     cout<<vis2[i]<<" ";
        // }
        int mini=vis1[n-1];
        vector<bool>visEdges(e.size(),false);
        for(int i=0;i<e.size();i++){
            int f=e[i][0],s=e[i][1],w=e[i][2];
            int val1=vis1[f]+vis2[s]+w;
            int val2=vis1[s]+vis2[f]+w;
            if(val1==mini||val2==mini){
                visEdges[i]=true;
            }
        }
        return visEdges;
    }
};