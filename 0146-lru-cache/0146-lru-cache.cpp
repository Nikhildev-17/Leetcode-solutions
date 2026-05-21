class LRUCache {
public:

    class Node{
        public:
            int key, val;
            Node* prev, *next;

            Node(int k, int v){
                key = k;
                val = v;
                prev = next = NULL;
            }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    unordered_map<int, Node*> m;
    int limit;

    LRUCache(int capacity) {
        limit = capacity;
        head -> next = tail;
        tail -> prev = head;
    }
    
    int get(int key) {
        if(m.find(key) == m.end()){
            return -1;
        }
        int ans = m[key] -> val;
        Node* ansNode = m[key];

        delNode(ansNode);

        addNode(ansNode);

        return ans;
    }

    void addNode(Node* newNode){
        Node* oldNext = head -> next;
        head -> next = newNode;
        newNode -> prev = head;
        newNode -> next = oldNext;
        oldNext -> prev = newNode;
    }

    void delNode(Node* oldNode){
        oldNode -> next -> prev = oldNode -> prev;
        oldNode -> prev -> next = oldNode -> next;
    }
    
    void put(int key, int value) {

        if(m.find(key) != m.end()){
            Node* oldNode = m[key];
            delNode(oldNode);
            m.erase(key);
        }

        if(m.size() == limit){
            m.erase(tail -> prev -> key);
            delNode(tail -> prev);
        }

        Node* newNode = new Node(key, value);
        addNode(newNode);
        m[key] = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */