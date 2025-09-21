class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        int tot=m+n;
        if(m>n){
            return findMedianSortedArrays(nums2,nums1);
        }
        //first always smaller array, 2nd always bigger or equal in size
        int si=0,ei=min(m,tot/2);
        while(si<=ei){
            int mid=si+(ei-si)/2;
            int elementsFromSecond=tot/2-mid;
            int end1=mid-1;
            int end2=elementsFromSecond-1;
            int st1 = mid,st2=elementsFromSecond;
            // bool isPossible=true;
            if(end1>=0&&st2<n && nums1[end1]>nums2[st2]){
                // if(nums1[end1]>nums2[st2]){
                    // isPossible=false;
                    ei=mid-1;
                // }
            }
            else if(end2>=0&&st1<m && nums2[end2]>nums1[st1]){
                // if(nums2[end2]>nums1[st1]){
                    // isPossible=false;
                    si=mid+1;
                // }
            }
            else{
                int ans1=INT_MIN,ans2=INT_MAX;
                if(tot%2==0){
                    if(end1>=0){
                        ans1=max(ans1,nums1[end1]);
                    }
                    if(end2>=0){
                        ans1=max(ans1,nums2[end2]);
                    }
                    if(st2<n){
                        ans2=min(ans2,nums2[st2]);
                    }
                    if(st1<m){
                        ans2=min(ans2,nums1[st1]);
                    }
                    return (double)(ans1+ans2)/2;
                }
                else{
                    int ans=INT_MAX;
                    if(st2<n){
                        ans=min(ans,nums2[st2]);
                    }
                    if(st1<m){
                        ans=min(ans,nums1[st1]);
                    }
                    return ans;
                }
            }
        }
        return -1;
    }
};