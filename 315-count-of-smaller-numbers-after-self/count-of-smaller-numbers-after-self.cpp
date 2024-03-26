#define pi pair<int, int>
class Solution {
private:
    vector<int> ans;
    vector<pi> merge(vector<pi>& l, vector<pi>& r) {
        for (int i = 0; i < l.size(); i++) {
            int si = 0, ei = r.size() - 1;
            int freq = -1;
            while (si <= ei) {
                int mid = si + (ei - si) / 2;
                int val = r[mid].first;
                if (val >= l[i].first) {
                    ei = mid - 1;
                } else {
                    freq = mid;
                    si = mid + 1;
                }
            }
            ans[l[i].second] += freq + 1;
        }
        int i = 0, j = 0;
        vector<pi> temp;
       
        while (i < l.size() && j < r.size()) {
            // cout << i << " " << j << endl;
            if (l[i].first < r[j].first) {
                temp.push_back(l[i++]);
            } else {
                temp.push_back(r[j++]);
            }
        }
        // cout<<"OUT"<<endl;
        while (i < l.size()) {
            temp.push_back(l[i++]);
        }
        while (j < r.size()) {
            temp.push_back(r[j++]);
        }
        return temp;
    }
    vector<pi> fun(vector<int>& nums, int i, int j) {
        vector<pi> t;
        if (i > j) {
            return t;
        } else if (i == j) {
            t.push_back({nums[i], i});
            return t;
        }
        int mid = i + (j - i) / 2;
        vector<pi> l = fun(nums, i, mid);
        vector<pi> r = fun(nums, mid + 1, j);
        t = merge(l, r);
        return t;
    }

public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        ans.resize(n, 0);
        fun(nums, 0, n - 1);
        return ans;
    }
};