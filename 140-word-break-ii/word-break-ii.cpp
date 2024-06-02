class Solution {
private:
    void fun(vector<string>& ans, string temp,string fin, int ind,
             unordered_map<string, int>& m, string& s) {
        if (ind >= s.size()) {
            if (temp.size() == 0) {
                ans.push_back(fin);
            }
            return;
        }
        temp+=s[ind];
        fun(ans,temp,fin,ind+1,m,s);
        if(m.find(temp)!=m.end()){
            // fin
            if(fin.size()!=0){
                fin+=" ";
            }
            fun(ans,"",fin+temp,ind+1,m,s);
        }
    }

public:
    vector<string> wordBreak(string s, vector<string>& w) {
        unordered_map<string, int> m;
        for (int i = 0; i < w.size(); i++) {
            m[w[i]]++;
        }
        string temp;
        vector<string> ans;
        fun(ans, "","", 0, m, s);
        return ans;
    }
};