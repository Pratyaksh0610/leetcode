#define pi pair<int, int>
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& b) {
        vector<vector<int>> ans;
        int n = b.size();
        vector<pi> v;
        for (int i = 0; i < n; i++) {
            v.push_back({b[i][0], b[i][2]});
            v.push_back({b[i][1], -b[i][2]});
        }
        sort(v.begin(), v.end());
        n = v.size();
        unordered_map<int, int> m;
        set<int> s;

        // vector<int> temp = {v[0].first, v[0].second};
        // ans.push_back(temp);

        int prev = -1;
        // m[v[0].second]++;
        // s.insert(v[0].second);
        int i = 0;
        while (i < n) {
            if (v[i].second < 0) {
                m[-v[i].second]--;
            } else {
                s.insert(v[i].second);
                m[v[i].second]++;
            }
            while (true) {
                auto it = s.rbegin();
                if (s.size() && m[*it] == 0) {
                    s.erase(*(it));
                } else {
                    break;
                }
            }
            if (i < n - 1 && v[i + 1].first == v[i].first) {
                i++;
                continue;
            }
            if (s.size() == 0) {
                if (prev != 0) {

                    vector<int> t;
                    t.push_back(v[i].first);
                    t.push_back(0);
                    ans.push_back(t);
                    prev = 0;
                }
            } else {
                int ele = *(s.rbegin());
                if (ele == prev) {
                    i++;
                    continue;
                }
                prev = ele;
                vector<int> t;
                t.push_back(v[i].first);
                t.push_back(prev);
                ans.push_back(t);
            }
            i++;
        }
        return ans;
    }
};