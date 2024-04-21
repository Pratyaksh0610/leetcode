#define pi pair<int, int>

class p {
public:
    int node, wt, ind;
    string s;
    p(int a, int b, int c, string s1) {
        node = a, wt = b, ind = c;
        s = s1;
    }
};

class compa {
public:
    bool operator()(p& a, p& b) {
        if (a.wt > b.wt) {
            return true;
        }
        return false;
    }
};

class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& e) {
        vector<vector<p>> v(n);
        for (int i = 0; i < e.size(); i++) {
            int f = e[i][0], s = e[i][1], w = e[i][2];
            v[f].push_back(p(s, w, i, ""));
            v[s].push_back(p(f, w, i, ""));
        }

        vector<bool> vis(e.size(), false);
        vector<int> visNodes(n, INT_MAX);
        visNodes[0] = 0;


        priority_queue<p, vector<p>, compa> pq;
        for (int i = 0; i < v[0].size(); i++) {
            p temp = v[0][i];
            pq.push(temp);
        }

        while (pq.size()) {
            p temp = pq.top();
            pq.pop();

            int node = temp.node, wt = temp.wt, ind = temp.ind;
            string path=temp.s;

            if (wt <= visNodes[node]) {
                visNodes[node] = wt;
                if (node == n - 1) {
                    // cout<<temp.s<<endl;
                    string t1 = "";
                    for (int i = 0; i < temp.s.size(); i++) {
                        if (temp.s[i] == ',') {
                            if (t1.size()) {
                                int val = stoi(t1);
                                vis[val] = true;
                            }
                            t1 = "";
                        } else {
                            t1 += temp.s[i];
                        }
                    }
                    if (t1.size()) {
                        int val = stoi(t1);
                        vis[val] = true;
                    }
                    vis[ind]=true;
                    continue;
                }
                for (int i = 0; i < v[node].size(); i++) {
                    p tt = v[node][i];
                    tt.wt = tt.wt + wt;
                    tt.s = temp.s + ',' + to_string(ind);
                    pq.push(tt);
                }
            }
        }

        return vis;
    }
};