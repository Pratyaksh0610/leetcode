class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>>ans;
        vector<int>f={1};
        ans.push_back(f);
        // n--;
        for(int i=2;i<=n;i++){
            // cout<<"LOOP"<<endl;
            vector<int>temp;
            for(int j=0;j<i;j++){
                int sum=0;
                if(j!=0){
                    sum+=ans[i-2][j-1];
                }
                if(j!=i-1){
                    sum+=ans[i-2][j];
                }
                temp.push_back(sum);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};