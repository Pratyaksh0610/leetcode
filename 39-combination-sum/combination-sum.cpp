class Solution {
    private:
    void generateCombinations(vector<vector<int>>&ans,vector<int>&c,vector<int>temp,int target,int index){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        else if(target<0 || index>=c.size()){
            return;
        }
        generateCombinations(ans,c,temp,target,index+1);
        while(target>=c[index]){
            temp.push_back(c[index]);
            target-=c[index];
            generateCombinations(ans,c,temp,target,index+1);
        }
        return;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& c, int target) {
        vector<vector<int>>ans;
        int n=c.size();
        vector<int>temp;
        generateCombinations(ans,c,temp,target,0);
        return ans;
    }
};