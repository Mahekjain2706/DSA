#include<bits/std++.h>
using namespace std;

// Least frequently used (LFU)
// get function -> get the value of key if exsists,else -1.
// put function -> update the value of key present,on insert the key f not present.
// when the caches become full, you remove the LFU one & if tie , then remove lru
// T.C O(1)
// we use twp maps freq map, keynode capacity,freq,size given
// check it is present previously or not.
// if their is another value with same key value then change its value and increase its freq.

class Node{
    public:
    int key,value,cnt;
    Node* next;
    Node* prev;

    Node(int _key,int _value){
        this->key = -key;
        this->value = value;
        this->cnt = 1;
    }
};
class List{
    int size;
    Node* head;
    Node* tail;

    List(){
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
        size=0;
    }

    void addFront(Node* node){
        Node* temp = head->next;
        node->prev = head;
        head->next = node;
        temp->prev = node;
        node->next = temp;
        size++;
    }

    void removeNode(Node* delNode){
        Node* delprev = delnode->prev;
        Node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
        size--;
    }
};

class LFUCcahe{
    map<int,Node*> keyNode;
    map<int,List*> freqListMap;
    int maxSizeCache;
    int minFreq;
    int curSize;

    public:
    LFUCache(int capacity){
        maxSizeCache = capacity;
        miniFreq = 0;
        curSize = 0;
    }

    void updateFreqListMap(Node* node){
        keyNode.erase(node->key);
        freqListMap[node->cnt]->removeNode(node);
        if(node->cnt == minFreq && freqListMap[node->cnt]->size==0){
            minFreq++:
        }

        List* nextHigherFreqList = new List();
        if(freqListMap.find(node->cnt + 1) != freqListMap.end()){
            nextHigherFreqList = freqListMap[node->cnt + 1];
        }
        node->cnt += 1;
        nextHigherFreqList->addFront(node);
        freqListMap[node->cnt] = nextHigherFreqList;
        keyNode[node->key] = node;
    }

        int get(int key){
            if(keyNode.find(key) != keyNode.end()){
                Node* node = keyNode[key];
                int val = node->value;
                updateFreqListMap(node);
                return val;
            }
            return -1;
        }

        void put(int key,int value){
            if(maxSizeCache==0){
                return;
            }
            if(keyNode.find(key)!=keyNode.end()){
                Node* node = keyNode[key];
                node->value = value;
                updateFreqListMap(node);
            }
            else{
                if(currSize==maxSizeCache){
                    List* list = freqListMap[minFreq];
                    keyNode.erase(list->tail->prev->key);
                    freqListMap[min[Freq]]->removeNode(list->tail->prev);
                }
                Node* node = new Node(key,value);
                listFreq->addFront(key,value);
                keyNode[key] = node;
                freqListMap[minFreq] = listFreq;
            }
        }
};


int main(){
    return 0;
}