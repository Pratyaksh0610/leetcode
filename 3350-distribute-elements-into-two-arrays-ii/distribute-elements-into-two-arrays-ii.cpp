#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define pi pair<int, int>

typedef __gnu_pbds::tree<pi, __gnu_pbds::null_type, greater<pi>,
                         __gnu_pbds::rb_tree_tag,
                         __gnu_pbds::tree_order_statistics_node_update>
    ordered_set;

    class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        ordered_set s1,s2;
        int n=nums.size();
        vector<int>arr1,arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        s1.insert({nums[0],0});
        s2.insert({nums[1],1});
        for(int i=2;i<n;i++){
            int a=arr1.size(),b=arr2.size();
            int f1=s1.order_of_key({nums[i],INT_MAX});
            int f2=s2.order_of_key({nums[i],INT_MAX});
            // cout<<f1<<" "<<f2<<endl;
            if(f1>f2){
                arr1.push_back(nums[i]);
                s1.insert({nums[i],i});
            }
            else if(f1<f2){
                arr2.push_back(nums[i]);
                s2.insert({nums[i],i});
            }
            else{
                if(b<a){
                    arr2.push_back(nums[i]);
                    s2.insert({nums[i],i});
                }
                else{
                    arr1.push_back(nums[i]);
                    s1.insert({nums[i],i});
                }
            }
        }
        vector<int>ans;
        for(int i=0;i<arr1.size();i++){
            ans.push_back(arr1[i]);
        }
        for(int i=0;i<arr2.size();i++){
            ans.push_back(arr2[i]);
        }
        return ans;
    }
};