class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = 0, j = 0;
        string ans;
        reverse(s.begin(), s.end());
        while (i < n && s[i] == ' ') {
            i++;
        }
        j = i;
        while (j < n) {
            if (s[j] != ' ') {
                j++;
            } else {
                // eulb_
                // i   j
                if (ans.size()) {
                    ans += " ";
                }
                int ind = j - 1;
                while (ind >= i) {
                    ans += s[ind--];
                }
                i = j;
                while (i < n && s[i] == ' ') {
                    i++;
                }
                j = i;
            }
        }
        if (s[j - 1] != ' ') {
            if (ans.size()) {
                ans += " ";
            }
            int ind = j - 1;
            while (ind >= i) {
                ans += s[ind--];
            }
        }
        return ans;
    }
};