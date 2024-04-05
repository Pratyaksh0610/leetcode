struct Node {
	Node *links[26];
	bool flag = false;
	//checks if the reference trie is present or not
	bool containKey(char ch) {
		return (links[ch - 'a'] != NULL);
	}
	//creating reference trie
	void put(char ch, Node *node) {
		links[ch - 'a'] = node;
	}
	//to get the next node for traversal
	Node *get(char ch) {
		return links[ch - 'a'];
	}
	//setting flag to true at the end of the word
	void setEnd() {
		flag = true;
	}
	//checking if the word is completed or not
	bool isEnd() {
		return flag;
	}
    void removeEnd(){
        flag=false;
    }
};
class Trie {
// public:
public:
	Node* root;
	Trie() {
		//creating new obejct
		root = new Node();
	}

	void insert(string word) {
		//initializing dummy node pointing to root initially
		Node *node = root;
		for (int i = 0; i < word.size(); i++) {
			if (!node->containKey(word[i])) {
				node->put(word[i], new Node());
			}
			//moves to reference trie
			node = node->get(word[i]);
		}
		node->setEnd();
	}

    void fun(Node*node,int i,int j,vector<vector<bool>>&vis,vector<vector<char>>&b,vector<string>&s,string w){
        int r=b.size(),c=b[0].size();
        if(i<0||i>=r||j<0||j>=c||vis[i][j]){
            return;
        }
        // Node*node=root;
        int ind=b[i][j]-'a';
        if(!node->containKey(b[i][j])){
            return;
        }
        node=node->links[ind];
        w.push_back(b[i][j]);
        if(node->isEnd()){
            s.push_back(w);
            node->removeEnd();
        }
        vis[i][j]=true;
        int row[]={-1,0,1,0};
        int col[]={0,-1,0,1};
        for(int k=0;k<4;k++){
            fun(node,i+row[k],j+col[k],vis,b,s,w);
        }
        vis[i][j]=false;
        
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& b, vector<string>& w) {
        int r=b.size(),c=b[0].size(),n=w.size();
        vector<string>ans;
        Trie t;
        for(int i=0;i<n;i++){
            t.insert(w[i]);
        }
        vector<vector<bool>>vis(r,vector<bool>(c,0));
        // set<string>s;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                t.fun(t.root,i,j,vis,b,ans,"");
            }
        }
        // for(auto it:s){
        //     ans.push_back(it);
        // }

        return ans;
    }
};