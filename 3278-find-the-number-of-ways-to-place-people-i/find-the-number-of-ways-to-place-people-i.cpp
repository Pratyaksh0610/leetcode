class Solution {
    static bool cmp(vector<int> a,vector<int> b){
        if(a[0]<b[0]) return true;
        else if(a[0]>b[0]) return false;
        else if(a[1]>b[1]){
            return true;
        }
        return false;
    }
public:
    int numberOfPairs(vector<vector<int>>& p) {
        int n=p.size(),cnt=0;
        sort(p.begin(),p.end(),cmp);
        for(int i=0;i<n;i++){
            int upperY=p[i][1];
            int lowerY=INT_MIN;
            for(int j=i+1;j<n;j++){
                int currentY=p[j][1];
                if(currentY<=upperY&&currentY>lowerY){
                    cnt++;
                    lowerY=currentY;
                }
                if(currentY==upperY){
                    break;
                }
            }
        }
        return cnt;
    }
};