#define pi pair<int,int>
class Solution {
    private:
    void fun(int node, vector<vector<pi>>& e,vector<int>&vis,int cnt,int &val){
        if(vis[node]!=-1){
            return;
        }
        vis[node]=cnt;
        for(int i=0;i<e[node].size();i++){
            // cout<<e[node][i].second<<endl;
            val=val&(e[node][i].second);
            fun(e[node][i].first,e,vis,cnt,val);
        }
        return;
    }
public:
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& q) {
        vector<vector<pi>>e(n);
        for(int i=0;i<edges.size();i++){
            int f=edges[i][0],s=edges[i][1],w=edges[i][2];
            e[f].push_back({s,w});
            e[s].push_back({f,w});
        }
        vector<int>vis(n,-1);
        unordered_map<int,int>m;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                int val=INT_MAX;
                fun(i,e,vis,cnt,val);
                m[cnt]=val;
                cnt++;
            }
        }

        vector<int>ans;
        for(int i=0;i<q.size();i++){
            int f=q[i][0],s=q[i][1];
            if(vis[f]!=vis[s]){
                ans.push_back(-1);
            }
            else if(f==s){
                ans.push_back(0);
            }
            else{
                ans.push_back(m[vis[f]]);
            }
        }
        return ans;
    }
};