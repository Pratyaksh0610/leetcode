class Solution {
    private:
    void addWord(string &ans,string &temp){
        if (temp.size()) {
            reverse(temp.begin(), temp.end());
            if (ans.empty()) {
                ans = temp;
            } else {
                ans = ans + " " + temp;
            }
            temp="";
        }
    }
public:
    string reverseWords(string s) {
        string ans, temp;
        int n = s.size();
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == ' ') {
                addWord(ans,temp);
            } else if (s[i] != ' ') {
                temp.push_back(s[i]);
            }
        }
        addWord(ans,temp);
        return ans;
    }
};