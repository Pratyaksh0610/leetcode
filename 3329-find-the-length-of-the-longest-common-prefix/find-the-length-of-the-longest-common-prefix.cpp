class Node{
    public:
    Node* links[10];
    // bool flag=false;
};

class Trie{
    private:
    Node*root;
    public:
    Trie(){
        root=new Node();
    }

    void insert(string word){
        Node*node=root;
        for(int i=0;i<word.size();i++){
            if(!node->links[word[i]-'0']){
                node->links[word[i]-'0']=new Node();
            }
            node=node->links[word[i]-'0'];
        }
        // node->flag=true;
    }
    int prefCheck(string word){
        Node*node=root;
        int maxi=0;
        for(int i=0;i<word.size();i++){
            if(!node->links[word[i]-'0']){
                return maxi;
            }
            node=node->links[word[i]-'0'];
            // if(node->flag){
                maxi=i+1;
            // }
        }
        return maxi;
    }
};
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        Trie t;
        for(int i=0;i<arr1.size();i++){
            t.insert(to_string(arr1[i]));
        }
        int ans=0;
        for(int i=0;i<arr2.size();i++){
            int val=t.prefCheck(to_string(arr2[i]));
            ans=max(ans,val);
        }
        return ans;
    }
};