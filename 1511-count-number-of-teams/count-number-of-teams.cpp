#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>,
                         __gnu_pbds::rb_tree_tag,
                         __gnu_pbds::tree_order_statistics_node_update>
    ordered_set;
class Solution {
public:
    int numTeams(vector<int>& r) {
        ordered_set s, s2;
        int n = r.size();
        vector<int>v(n,0);
        int ans = 0;
        for (int i = 1; i < n; i++) {
            v[i-1]=s.order_of_key(r[i-1]);
            for (int j = 0; j < i; j++) {
                if (r[j] >= r[i]) {
                    continue;
                }
                ans+=v[j];
            }
            s.insert(r[i-1]);
        }
        for (int i = n - 2; i >= 0; i--) {
            v[i+1]=s2.order_of_key(r[i+1]);
            for (int j = n - 1; j > i; j--) {
                if (r[j] >= r[i]) {
                    continue;
                }
                ans += v[j];
            }
            s2.insert(r[i+1]);
        }
        return ans;
    }
};