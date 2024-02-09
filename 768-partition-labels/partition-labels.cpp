class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n=s.size();
        unordered_map<char,int>m;
        for(int i=0;i<n;i++){
            m[s[i]]=i;
        }
        vector<int>ans;
        int i=0;
        while(i<n){
            int till=m[s[i]];
            int j=i;
            while(j<=till){
                till=max(till,m[s[j]]);
                j++;
            }
            ans.push_back(j-i);
            i=j;
        }
        return ans;
    }
};