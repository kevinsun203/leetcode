#include "unordered_map"
using namespace std;

class Node{
    public:
        int val;
        int key;
        Node *next;
        Node *prev;
        Node(int x, int y) : val(x), key(y), next(nullptr), prev(nullptr) {}
};
// Map -> O(1) lookup, doubly linked list -> O(1) insertion. Whenever a node is accessed or updated, 
// it is moved to the back of the list. Upon eviction, the head of the list is removed
class LRUCache {
    private:
        int maxCapacity;
        int currentCapacity;
        unordered_map<int, Node*> cache;

        // doubly linked list
        Node* head; // LRU cache
        Node* tail; // MRU cache
        
public:
    LRUCache(int capacity) {
        maxCapacity = capacity;
        currentCapacity = 0;
        head = nullptr;
        tail = nullptr;
    }

    void move(Node* toMove) {
        // moves node to the end of the list
        if (tail != toMove) {
            // remove node from its position in the list
            Node* prevNode = toMove->prev;
            Node* nextNode = toMove->next;
            if (prevNode != nullptr) {
                prevNode->next = nextNode;
            }
            if (nextNode != nullptr) {
                nextNode->prev = prevNode;
            }

            // adjust head pointer if needed
            if (toMove == head && nextNode != nullptr) {
                head = nextNode;
            }
                
            // Move node to the right of the tail
            tail->next = toMove;
            toMove->prev = tail;
            toMove->next = nullptr;
            tail = toMove;
        }
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            // move node to the back of the list
            Node* toMove = cache[key];
            move(toMove);

            return cache[key]->val;
        } else {
            return -1;
        }
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            // update value if the key is present 
            cache[key]->val = value;
            Node* toMove = cache[key]; 

            // move node to the back of the list
            move(toMove);

        } else {
            Node* toAdd = new Node(value, key);
            if (head == nullptr) {
                // first time adding something to the list
                head = toAdd;
                tail = head;
                cache[key] = head;
                currentCapacity++;
            } else {
                if (currentCapacity + 1 > maxCapacity) {
                    // evict current head of list if capacity is exceeded
                    Node* curHead = head;
                    head = head->next;
                    if (head != nullptr) {
                        head->prev = nullptr;
                    }
                    tail = head == nullptr ? nullptr : tail;
                    cache.erase(curHead->key);
                    delete curHead;
                    currentCapacity--;
                }              
                // add new node to the end of the list
                if (head == nullptr) {
                    head = toAdd;
                    tail = head;
                    cache[key] = head;
                } else {
                    tail->next = toAdd;
                    toAdd->prev = tail;
                    toAdd->next = nullptr;
                    tail = toAdd;
                    cache[key] = tail;
                }
                currentCapacity++;
            }

        } 
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */