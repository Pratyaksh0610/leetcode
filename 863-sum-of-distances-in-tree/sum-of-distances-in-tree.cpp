#define pi pair<int,int>

class Solution {
    private:
    // int found=0;
    pi fill(int node,vector<vector<int>>&e,vector<int>&vis,int parent,vector<pi>&info){
        vis[node]=parent;
        int foundNodes=0,sum=0;
        for(int i=0;i<e[node].size();i++){
            if(e[node][i]!=parent){
                pi temp=fill(e[node][i],e,vis,node,info);
                foundNodes+=temp.first;
                sum+=temp.second;
            }
        }
        // b[node]=sum+foundNodes;
        sum+=foundNodes;
        return info[node]= {foundNodes+1,sum};
    }
    // pi upfill(int node,vector<int>&vis,vector<pi>&up){
    //     // vis[node]=parent;
    //     if(up[node].first!=-1){
    //         return up[node];
    //     }
    //     int foundNodes=0,sum=0;
    //     if(vis[node]!=-1){
    //         pi temp=upfill(vis[node],vis,up);
    //         foundNodes+=temp.first;
    //         sum+=temp.second;
    //     }
    //     return up[node]= {foundNodes,sum+foundNodes-2};
    // }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& e) {
        vector<int>parent(n,-1);//visited
        vector<int>ans(n,-1);
        // vector<int>belowVal(n,-1);
        // vector<pi>upVal(n,{-1,-1});
        vector<pi>info(n);
        vector<vector<int>>edges(n);
        for(int i=0;i<e.size();i++){
            int f=e[i][0],s=e[i][1];
            edges[f].push_back(s);
            edges[s].push_back(f);
        }
        pi origin=fill(0,edges,parent,-1,info);
        ans[0]=origin.second;
        queue<int>q;
        for(int i=0;i<edges[0].size();i++){
            q.push(edges[0][i]);
        }
        // for(int i=0;i<n;i++){
        //     cout<<info[i].first<<" "<<info[i].second<<endl;
        // }
        while(q.size()){
            int s=q.size();
            while(s>0){
                int node=q.front();
                q.pop();
                s--;
                for(int i=0;i<edges[node].size();i++){
                    if(edges[node][i]!=parent[node]){
                        q.push(edges[node][i]);
                    }
                }
                int p=parent[node];
                int pcount=info[p].first,psum=info[p].second;
                ans[node]=info[node].second+psum-(info[node].first+info[node].second)+pcount-info[node].first;
                info[node]={ans[node],n};
            }
        }
        return ans;
    }
};