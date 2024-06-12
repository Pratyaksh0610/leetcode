class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int total = n1 + n2 - 1;
        int arrived = total / 2;
        int si = 0, ei = n1;
        while (si <= ei) {
            int mid = si + (ei - si) / 2;
            // mid mtlb kitne elements le rhe hai
            int rem = arrived - mid;
            if (rem < 0) {
                // cout<<"CONTI: "<<rem<< " mid: "<<mid<<endl; 
                ei = mid - 1;
                continue;
            }
            else if(rem>n2){
                si=mid+1;
                continue;
            }
            int l1, r1, l2, r2;
            // cout<<"MID: "<<mid<<" rem: "<<rem<<endl;
            l1 = (mid - 1 >= 0&&mid-1<n1) ? nums1[mid - 1] : INT_MIN;
            r1 = (mid < n1&&mid>=0) ? nums1[mid] : INT_MAX;
            l2 = (rem - 1 >= 0&&rem-1<n2) ? nums2[rem - 1] : INT_MIN;
            r2 = (rem < n2&&rem>=0) ? nums2[rem] : INT_MAX;
            // cout << l1 << " " << r1 << " " << l2 << " " << r2 << endl;

            if (l1 <= r2 && l2 <= r1) {
                int first = min(r1, r2);
                if (total % 2 == 0) {
                    return first;
                }
                // cout << l1 << " " << r1 << " " << l2 << " " << r2 << endl;
                double ans = 0;
                int cnt = 0;
                while (cnt < 2) {
                    if (r1 <= r2 && r1 != INT_MIN) {
                        ans += r1;
                        r1 = (mid + 1 < n1) ? nums1[mid + 1] : INT_MAX;
                        cnt++;
                    } else if (r2 <= r1 && r2 != INT_MIN) {
                        ans += r2;
                        r2 = (rem + 1 < n2) ? nums2[rem + 1] : INT_MAX;
                        cnt++;
                    }
                    // cout << l1 << " " << r1 << " " << l2 << " " << r2 << endl;
                }
                ans /= 2;
                return ans;
            } else if (l1 > r2) {
                ei = mid - 1;
            } else if (l2 > r1) {
                si = mid + 1;
            }
        }
        return -1;
    }
};