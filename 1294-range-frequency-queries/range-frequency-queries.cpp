#define pi pair<int,int>
class RangeFreqQuery {
    private:
    vector<pi>v;
public:
    RangeFreqQuery(vector<int>& arr) {
        int n=arr.size();
        for(int i=0;i<arr.size();i++){
            v.push_back({arr[i],i});
        }
        sort(v.begin(),v.end());
    }
    
    int query(int left, int right, int value) {
        pi st={value,left};
        pi end={value,right};
        auto l=lower_bound(v.begin(),v.end(),st);
        auto r=upper_bound(v.begin(),v.end(),end);
        if(l==v.end()){
            return 0;
        }
        return (r-l);
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */