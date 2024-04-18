#define pi pair<int, int>

class Solution {
public:
    int maxEvents(vector<vector<int>>& e) {
        //[1,5],[1,5],[1,5],[3,3]
        int n = e.size();
        sort(e.begin(), e.end());
        int day = 1, ind = 0;
        int ans = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        while (ind < e.size()) {
            if (day == e[ind][0]) {
                pq.push(e[ind][1]);
                ind++;
                if (ind == n)
                    break;
            }
            while (day < e[ind][0] && pq.size()) {
                int exp = pq.top();
                pq.pop();
                if (exp >= day) {
                    ans++;
                    day++;
                }
            }
            if (e[ind][0] > day) {
                day = e[ind][0];
            }
        }
        while (pq.size()) {
            int exp = pq.top();
            pq.pop();
            if (exp >= day) {
                ans++;
                day++;
            }
        }
        return ans;
    }
};