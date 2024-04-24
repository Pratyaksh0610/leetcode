#define pi pair<int,int>

class Solution {
    int dfsl(vector<vector<int>>&e,int node,int parent,vector<int>&dist,int curr){
        if(dist[node]!=-1){
            cout<<"AAYA"<<endl;
            return dist[node];
        }
        dist[node]=curr;
        int pass=curr+1;
        //curr+1 pass hoga , adding current node;
        int val=0;
        for(int i=0;i<e[node].size();i++){
            if(e[node][i]==parent) continue;
            int below=dfsl(e,e[node][i],node,dist,pass);
            //ab below se value aayi hai, isko pass se compare kr after +1
            pass=max(pass,below+1);
            val=max(val,below);
        }
        dist[node]=pass-1;
        return val+1;
    }
    int right(vector<vector<int>>&e,int node,int parent,vector<int>&dist,int curr){
        // if(dist[node]!=-1){
        //     cout<<"AAYA"<<endl;
        //     return dist[node];
        // }
        // dist[node]=curr;
        dist[node]=max(dist[node],curr);
        int pass=curr+1;
        //curr+1 pass hoga , adding current node;
        int val=0;
        for(int i=e[node].size()-1;i>=0;i--){
            if(e[node][i]==parent) continue;
            int below=right(e,e[node][i],node,dist,pass);
            //ab below se value aayi hai, isko pass se compare kr after +1
            pass=max(pass,below+1);
            val=max(val,below);
        }
        // dist[node]=pass-1;
        dist[node]=max(dist[node],pass-1);
        return val+1;
    }
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& e) {
        vector<vector<int>>edges(n);
        for(int i=0;i<e.size();i++){
            int f=e[i][0],s=e[i][1];
            edges[f].push_back(s);
            edges[s].push_back(f);
            // cout<<f<<" & "<<s<<endl;
        }
        // for(int i=0;i<n;i++){
        //     cout<<i<<endl;
        //     for(int j=0;j<edges[i].size();j++){
        //         cout<<edges[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        vector<int>dist(n,-1);
        dfsl(edges,0,-1,dist,0);
        right(edges,0,-1,dist,0);
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            mini=min(dist[i],mini);
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(dist[i]==mini){
                ans.push_back(i);
            }
        }
        return ans;
    }
};