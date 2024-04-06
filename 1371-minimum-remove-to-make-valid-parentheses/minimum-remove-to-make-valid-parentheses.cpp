#define pi pair<char, int>
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.size();
        stack<int> st;
        vector<bool> vis(n, true);

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                st.push(i);
            } else if (s[i] == ')') {
                if (st.size() == 0) {
                    vis[i] = false;
                } else {
                    st.pop();
                }
            }
        }

        while (st.size()) {
            int ind = st.top();
            st.pop();
            vis[ind] = false;
        }
        string ans;
        for (int i = 0; i < n; i++) {
            if (vis[i]) {
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};