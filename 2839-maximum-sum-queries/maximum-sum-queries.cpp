#define pi pair<int,int>
#define pii pair<int,pair<int,int>>
#define endl '\n'
class Solution {
    private:
//function to build the segment tree
void buildTree(int *tree,vector<pi>&temp,int index,int s,int e)
{
	//base case
	if(s>e)
		return;
	//reached leaf node
	if(s==e)
	{
		tree[index]=temp[s].first+temp[s].second;
		return ;
	}
	//now build the segment tree in bottom up manner
	int m = (s+e)/2;
	buildTree(tree,temp,2*index,s,m);
	buildTree(tree,temp,2*index+1,m+1,e);
	tree[index]= max(tree[2*index],tree[2*index+1]);
	return;
}

//function to query the segment tree for RMQ
int query(int *tree,int index,int s,int e,int qs,int qe)
{
	//base case: if query range is outside the node range
	if(qs>e || s>qe)
		return INT_MIN;
	//complete overlap
	if(s>=qs && e<=qe)
		return tree[index];
	//now partial overlap case is executed
	int m = (s+e)/2;
	int left_ans = query(tree,2*index,s,m,qs,qe);
	int right_ans = query(tree,2*index+1,m+1,e,qs,qe);
	return max(left_ans,right_ans);
}

public:
    vector<int> maximumSumQueries(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& q) {
        int n=nums1.size();
        int m=q.size();
        vector<int>ans(m,-1);
        //preserve index
        stack<pi>st;
        vector<pi>v,temp;
        vector<pii>qq;
        for(int i=0;i<m;i++){
            qq.push_back({q[i][0],{q[i][1],i}});
        }
        for(int i=0;i<n;i++){
            v.push_back({nums1[i],nums2[i]});
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            while(st.size()&&st.top().first<=v[i].first&&st.top().second<=v[i].second){
                st.pop();
            }
            st.push({v[i].first,v[i].second});
        }
        sort(qq.begin(),qq.end());
        // vector<pi>temp;
        while(st.size()){
            temp.push_back(st.top());
            st.pop();
        }
        int index = 1;									//index of 1st node
        int s =0,e=temp.size()-1;

        reverse(temp.begin(),temp.end());
        int *tree = new int[4*(temp.size())+1]; 
        buildTree(tree,temp,index,s,e);
        int i=0,j=0;
        while(i<m){
            int a=qq[i].first,b=qq[i].second.first,ind=qq[i].second.second;
            int si=0,ei=temp.size()-1;
            int ans1=INT_MAX,ans2=INT_MIN;
            while(si<=ei){
                int mid=si+(ei-si)/2;
                if(temp[mid].first<a){
                    si=mid+1;
                }
                else{
                    ei=mid-1;
                    ans1=min(ans1,mid);
                }
            }
            si=0,ei=temp.size()-1;
            while(si<=ei){
                int mid=si+(ei-si)/2;
                if(temp[mid].second<b){
                    ei=mid-1;
                }
                else{
                    si=mid+1;
                    ans2=max(ans2,mid);
                }
            }
            if(ans1<=ans2){
                ans[ind]=query(tree,1,0,temp.size()-1,ans1,ans2);
            }
            i++;
        }
        return ans;

    }
};