#include<bits/std++.h>
using namespace std;
// least recently use data structure where first last
// given a put key and val and get key
// and fixed size of cache given we have to implement it and if size of cache full then remove least recent used.
// T.C O(1)
// doubly link list
class LRUCache
{
    private:
    class Node{
        public:
        Node* prev;
        Node* next;
        int key,value;
        
        Node(int key,int value){
            this->key = key;
            this->value = value;
            prev = NULL;
            next = NULL;
        }
    };

    public:
    unordered_map<int,Node*> mp;
    int capacity;
    Node* head = new Node(0,0);
    Node* tail = new Node(0,0);
    LRUCache(int cap)
    {
        
        capacity = cap;
        head->next = tail;
        tail->prev = head;
        
    }
    void insert(Node* node){
        Node* headNext = head->next;
        head->next = node;
        node->prev = head;
        node->next = headNext;
        headNext->prev = node;
    }
    
    void removeN(Node* node){
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }
    //Function to return value corresponding to the key.
    int GET(int key)
    {
        if(mp.find(key)!=mp.end()){
            Node* node = mp[key];
            int res = node->value;
            mp.erase(key);
            removeN(node);
            insert(node);
            mp[key] = head->next;
            return res;
        }else{
            return -1;
        }
    }
    
    //Function for storing key-value pair.
    void SET(int key, int value)
    {
        if(mp.find(key)!=mp.end()){
            Node* existing = mp[key];
            mp.erase(key);
            removeN(existing);
        }
        if(mp.size()==capacity){
            Node* last = tail->prev;
            int ka = last->key;
            mp.erase(ka);
            removeN(last);
        }
        Node* node = new Node(key,value);
        insert(node);
        mp[key] = head->next;
    }
};

int main(){

    return 0;
}