class LRUCache {
public:
    class Node {
    public:
        int val;
        int key;
        Node* prev;
        Node* nex;
        Node(int key, int val) {
            this->key = key;
            this->val = val;
        }
    } ;
    unordered_map<int, Node*> mp;
    int cap;
    LRUCache(int capacity) {
         cap = capacity; 
         head->nex=tail;
         tail->prev=head;
         
    }
    Node*head=new Node(-1,-1);
    Node*tail=new Node(-1,-1);
    void addNode(Node*newNode){
        Node*temp=head->nex;
        newNode->nex=temp;
        
        newNode->prev=head;
        
        head->nex=newNode;
        temp->prev=newNode;
    }
    void deleteNode(Node*deleteNode){
           Node*previous=deleteNode->prev;
           Node*nexious=deleteNode->nex;
           previous->nex=nexious;
           nexious->prev=previous;
    }
    int get(int key) {
        if(mp.find(key)!=mp.end()){
           Node*curr=mp[key];
           int ans=curr->val;
           mp.erase(key);
           deleteNode(curr);
           addNode(new Node(key,ans));
           mp[key]=head->nex;
           return ans;
        }
        return -1;
    }

    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
           deleteNode(mp[key]);
           mp.erase(key);
        }
        if(mp.size()==cap){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }
        addNode(new Node(key,value));
        mp[key]=head->nex;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */