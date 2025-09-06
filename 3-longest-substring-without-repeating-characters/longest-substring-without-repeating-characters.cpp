class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (s.empty()) {
            return 0;
        }
        int ans = 1;
        unordered_map<char, int> m;
        int i = 0, j = 1;
        m[s[0]] = 1;

        while (j < n) {
            if (m.find(s[j]) == m.end()) {
                m[s[j]]++;
                j++;
            } else {
                while (i < j && m.find(s[j]) != m.end()) {
                    m[s[i]]--;
                    if (m[s[i]] == 0) {
                        m.erase(s[i]);
                    }
                    i++;
                }
                m[s[j]]++;
                j++;
            }
            ans = max(ans, j - i);
        }
        return ans;
    }
};