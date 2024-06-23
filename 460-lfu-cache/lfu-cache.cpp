#define pi pair<Node*, Node*>
class Node {
public:
    Node* next;
    Node* prev;
    int val,key;
    Node(int a,int b) { val = a,key=b;
    next=NULL;
    prev=NULL; }
};

class LFUCache {
public:
    int size = 0, curr = 0;
    unordered_map<int, Node*> allNodes;
    unordered_map<Node*, int> nodeFreq;
    map<int, pi> freqList;

    void putFirst(Node* head, Node* curr) {
        if (curr->prev) {
            curr->prev->next = curr->next;
            curr->next->prev = curr->prev;
        }
        curr->next = head->next;
        head->next->prev = curr;
        head->next = curr;
        curr->prev = head;
    }
    void deleteLast(Node* tail, unordered_map<int, Node*>& m) {
        // cout<<"ERASED :"<<tail->prev->val<<endl;
        m.erase(tail->prev->key);
        tail->prev->prev->next = tail;
        tail->prev = tail->prev->prev;
    }
    void deleteNode( Node* curr) {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
    }
    void createFreqList(map<int, pi>& freqList, int freq) {
        Node* head = new Node({-1,-1});
        Node* tail = new Node({-1,-1});
        head->next = tail;
        tail->prev = head;
        freqList[freq] = {head, tail};
    }

    LFUCache(int c) { size = c; }

    int get(int key) {
        if (allNodes.find(key) == allNodes.end()) {
            return -1;
        } else {
            Node* temp = allNodes[key];
            int freq = nodeFreq[temp];
            int ans = temp->val;

            pi nodePair = freqList[freq];
            deleteNode(temp);

            if (nodePair.first->next == nodePair.second) {
                freqList.erase(freq);
            }

            if (freqList.find(freq + 1) == freqList.end()) {
                // create list
                createFreqList(freqList, freq + 1);
            }
            int newFreq = freq + 1;
            nodePair = freqList[newFreq];
            putFirst(nodePair.first, temp);
            nodeFreq[temp]=newFreq;
            return ans;
        }
    }

    void put(int key, int value) {
        if (allNodes.find(key) == allNodes.end()) {
            curr++;
            if(curr>size){
                auto it=freqList.begin();
                int lowestFreq=it->first;
                pi nodePair=it->second;
                deleteLast(nodePair.second,allNodes);
                if(nodePair.first->next==nodePair.second){
                    freqList.erase(lowestFreq);
                }
                curr--;
            }
            // create new
            Node*temp=new Node({value,key});
            allNodes[key] = temp;

            // new node created, push into freq1 list
            // check if freq1 exists
            if (freqList.find(1) == freqList.end()) {
                // create list
                createFreqList(freqList, 1);
            }
            nodeFreq[allNodes[key]] = 1;
            pi nodePair = freqList[1];
            putFirst(nodePair.first, temp);
        } else {
            // exists, inc freq
            Node* temp = allNodes[key];
            int freq = nodeFreq[temp];
            pi nodePair = freqList[freq];
            deleteNode(temp);
            if (nodePair.first->next == nodePair.second) {
                freqList.erase(freq);
            }
            if (freqList.find(freq + 1) == freqList.end()) {
                // create list
                createFreqList(freqList, freq + 1);
            }
            int newFreq = freq + 1;
            int newVal = value;
            temp->val = newVal;
            nodePair = freqList[newFreq];
            putFirst(nodePair.first, temp);
            nodeFreq[temp]=newFreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */