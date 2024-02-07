class Solution {

public:
    string minWindow(string s, string t) {
        // cout << s.size() << endl;
        int m = s.size(), n = t.size();
        vector<vector<int>> v(m, vector<int>(53, 0));
        for (int i = 0; i < m; i++) {
            if (s[i] >= 'a') {
                int ind = s[i] - 'a' + 26;
                // cout<<ind<<" ";
                v[i][ind]++;
            } else {
                v[i][s[i] - 'A']++;
            }
        }
        // cout<<endl;
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < 53; j++) {
                v[i][j] += v[i - 1][j];
            }
        }
        unordered_map<char, int> mm;
        for (int i = 0; i < n; i++) {
            mm[t[i]]++;
        }

        string ans;
        int i = -1, j = 0;
        int mini = INT_MAX;
        int ind1 = -1, ind2 = -1;
        while (i <= j && j < m) {
            bool done = false;
            // cout<<i<<" "<<j<<endl;
            for (auto it : mm) {
                char ch = it.first;
                int freq = it.second;
                int ind = 0;
                if (ch >= 'a') {
                    ind = ch - 'a' + 26;
                } else {
                    ind = ch - 'A';
                }
                // cout<<ch<<" "<<ind<<endl;
                int value = v[j][ind];
                if (i >= 0) {
                    value -= v[i][ind];
                }
                if (value < freq) {
                    // j++;
                    done = true;
                    break;
                }
            }
            if (done) {
                j++;
                // break;
            } else {
                if (j - i < mini&&j-i>=n) {
                    // cout << i << " " << j << endl;
                    // cout<<"UP"<<endl;
                    mini = j - i;
                    ind1 = i, ind2 = j;
                }
                i++;
            }
            // i++;
        }
        // cout << ind1 << " " << ind2 << endl;

        if (ind2 == -1) {
            return "";
        }
        for (int k = ind1 + 1; k <= ind2; k++) {
            ans.push_back(s[k]);
        }
        return ans;
    }
};