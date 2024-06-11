class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int,int>m;
        for(int i=0;i<arr1.size();i++){
            m[arr1[i]]++;
        }
        int ind=0;
        for(int i=0;i<arr2.size();i++){
            int cnt=0;
            while(cnt<m[arr2[i]]){
                arr1[ind]=arr2[i];
                ind++;
                cnt++;
            }
            m.erase(arr2[i]);
        }
        for(auto it:m){
            int freq=it.second;
            int cnt=0;
            while(cnt<freq){
                arr1[ind]=it.first;
                ind++;
                cnt++;
            }
        }
        return arr1;
    }
};