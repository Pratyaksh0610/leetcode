#define pi pair<int,int>

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,vector<int>>m;
        for(int i=0;i<n;i++){
            m[arr[i]].push_back(i);
        }
        
        queue<pi>q;
        q.push({0,0});
        vector<int>dist(n,INT_MAX);

        while(q.size()){
            int s=q.size();
            while(s>0){
                pi temp=q.front();
                q.pop();
                s--;
                //agla, pichla
                int ind=temp.first;
                int cost=temp.second;
                if(ind>=n||ind<0||dist[ind]<=cost){
                    continue;
                }
                dist[ind]=cost;
                q.push({ind+1,dist[ind]+1});
                q.push({ind-1,dist[ind]+1});
                // cout<<arr[ind]<<" "<<ind<<" "<<cost<<endl;
                for(auto it:m[arr[ind]]){
                    if(it!=ind){
                        q.push({it,dist[ind]+1});
                        // continue;
                    }
                }
                if(m.find(arr[ind])!=m.end()){
                    m.erase(arr[ind]);
                }
            }
        }
        return dist[n-1];
    }
};