class Node{
    public:
    Node*next;
    Node*prev;
    int val,key;
    Node(int a,int b){
        next=NULL;
        prev=NULL;
        val=a;
        key=b;
    }
};

class LRUCache {
public:
int size=0,curr=0;
unordered_map<int,Node*>m;
Node*head=new Node(-1,-1);
Node*tail=new Node(-1,-1);

void putFirst(Node*head,Node*curr){
    if(curr->prev){
        curr->prev->next=curr->next;
        curr->next->prev=curr->prev;
    }
    curr->next=head->next;
    head->next->prev=curr;
    head->next=curr;
    curr->prev=head;
}
void putLast(Node*tail,Node*curr){
    curr->next=tail;
    tail->prev->next=curr;
    curr->prev=tail->prev;
    tail->prev=curr;
}
void deleteLast(Node*tail,unordered_map<int,Node*>&m){
    m.erase(tail->prev->key);
    tail->prev->prev->next=tail;
    tail->prev=tail->prev->prev;
}
    LRUCache(int c) {
        size=c;
        head->next=tail;
        tail->prev=head;
    }
    
    int get(int key) {
        // cout<<"GEt key: "<<key<<endl;
        if(m.find(key)==m.end()){
            // cout<<"Not_FOUND"<<endl;
            return -1;
        }
        Node*temp=m[key];
        putFirst(head,temp);
        // cout<<head->next->val<<endl;
        Node*temp2=head;
        // while(temp2){
        //     cout<<temp2->val<<" ";
        //     temp2=temp2->next;
        // }
        // cout<<endl;
        return temp->val;
    }
    
    void put(int key, int value) {
        // cout<<"put: "<<key<<" "<<value<<endl;
        // cout<<"curr: "<<curr<<endl;
        if(m.find(key)==m.end()){
            if(curr==size){
                deleteLast(tail,m);
                // cout<<"DEL "<<key<<endl;
                curr--;
            }
            m[key]=new Node(value,key);
            Node*temp=m[key];
            putFirst(head,temp);
            curr++;
        }
        else{
            Node*temp=m[key];
            temp->val=value;
            putFirst(head,temp);
        }
        // Node*temp=head;
        // while(temp){
        //     cout<<temp->val<<" ";
        //     temp=temp->next;
        // }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */