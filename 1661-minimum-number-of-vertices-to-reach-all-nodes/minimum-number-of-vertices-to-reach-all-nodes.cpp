class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& e) {
        vector<vector<int>>v(n);
        for(int i=0;i<e.size();i++){
            for(int j=0;j<e[i].size();j++){
                int f=e[i][0],s=e[i][1];
                v[s].push_back(f);
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(v[i].size()==0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};