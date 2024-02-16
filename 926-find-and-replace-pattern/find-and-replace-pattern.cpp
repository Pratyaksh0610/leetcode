class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& w, string p) {
        vector<string>temp;
        int val=0;
        string ans;
        unordered_map<char,int>m;
        for(int i=0;i<p.size();i++){
            if(m.find(p[i])==m.end()){
                m[p[i]]=val++;
            }
            ans.push_back(m[p[i]]);
        }
        for(int i=0;i<w.size();i++){
            string t;
            unordered_map<char,int>m2;
            bool done=true;
            val=0;
            for(int j=0;j<w[i].size();j++){
                if(m2.find(w[i][j])==m2.end()){
                m2[w[i][j]]=val++;
            }
                t.push_back(m2[w[i][j]]);
                if(ans[j]!=t[j]){
                    done=false;
                    break;
                }
            }
            if(done){
                temp.push_back(w[i]);
            }
        }
        return temp;
    }
};