#define ll long long int
class Solution {

ll bs(vector<int>& nums ,ll si,ll mid,ll ei){
    
    ll st=mid+1,end=ei;
    ll j=mid;
    while(st<=end){
        ll nmid=st+(end-st)/2;
        ll val=(ll)2*(ll)nums[nmid];
        if(val<(ll)nums[si]){
            j=max(j,nmid);
            st=nmid+1;
        }
        else{
            end=nmid-1;
        }
    }
    return j-mid;
}

ll merge(vector<int>& nums,ll si,ll mid,ll ei){
    if(si>=ei){
        return 0;
    }
    ll ans=0;
    for(ll i=si;i<=mid;i++){
        ans+=bs(nums,i,mid,ei);
    }
    sort(nums.begin()+si,nums.begin() +ei+1);
    return ans;

}

ll mergeSort(vector<int>& nums,ll si,ll ei){
    if(si>=ei){
        return 0;
    }
    ll mid=si+(ei-si)/2;
    ll val1=mergeSort(nums,si,mid);
    ll val2= mergeSort(nums,mid+1,ei);
    ll ans=merge(nums,si,mid,ei);
    return ans+val1+val2;
}
public:
    int reversePairs(vector<int>& nums) {
        ll n=nums.size();
        return mergeSort(nums,0,n-1);
    }
};