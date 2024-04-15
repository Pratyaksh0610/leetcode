#define ll long long int

class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<ll, vector<ll>, greater<ll>> pq;
        pq.push(1);
        unordered_map<ll, ll> m;
        while (pq.size()) {
            ll ele = pq.top();
            pq.pop();
            if (n == 1) {
                return ele;
            }
            n--;
            if (m.find(ele * 2) == m.end()) {
                m[ele * 2]++;
                pq.push(ele * 2);
            }
            if (m.find(ele * 3) == m.end()) {
                m[ele * 3]++;
                pq.push(ele * 3);
            }
            if (m.find(ele * 5) == m.end()) {
                m[ele * 5]++;
                pq.push(ele * 5);
            }
        }
        return -1;
    }
};