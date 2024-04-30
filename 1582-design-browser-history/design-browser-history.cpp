class Node{
    public:
    Node*prev=NULL;
    Node*next=NULL;
    Node*curr=NULL;
    string s;
};

class BrowserHistory {
public:
Node * curr;
    BrowserHistory(string homepage) {
        curr=new Node;
        curr->s=homepage;
    }
    
    void visit(string url) {
        curr->next=NULL;
        Node * vis=new Node;
        vis->s=url;
        curr->next=vis;
        vis->prev=curr;
        curr=curr->next;
    }
    
    string back(int steps) {
        while(steps>0&&curr&&curr->prev){
            curr=curr->prev;
            steps--;
        }
        return curr->s;
    }
    
    string forward(int steps) {
        while(steps>0&&curr&&curr->next){
            curr=curr->next;
            steps--;
        }
        return curr->s;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */