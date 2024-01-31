#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value){
        this->data = value;
        this->next = NULL;
        this->prev = NULL;
    }
};

class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    void insert_at_start(int num) {
        Node* newNode = new Node(num);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void remove_from_start() {
        if (head != NULL) {
            Node* temp = head;
            head = head->next;
            if (head != NULL) {
                head->prev = NULL;
            } else {
                tail = NULL;
            }
            delete temp;
        }
    }

    void insert_at_end(int num) {
        Node* newNode = new Node(num);
        if (tail == NULL) {
            head = tail = newNode;
        } else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
    }

    void remove_from_end() {
        if (tail != NULL) {
            Node* temp = tail;
            tail = tail->prev;
            if (tail != NULL) {
                tail->next = NULL;
            } else {
                head = NULL;
            }
            delete temp;
        }
    }

    int front(){
        if(head!=NULL) return head->data;
        return 0;
    }

    int last(){
        if(tail!=NULL) return tail->data;
        return 0;
    }
};

class Deque {
private:
    LinkedList linkedList;

public:
    Deque() {}

    void push_back(int num) {
        linkedList.insert_at_end(num);
    }

    void push_front(int num) {
        linkedList.insert_at_start(num);
    }

    void pop_back() {
        linkedList.remove_from_end();
    }

    void pop_front() {
        linkedList.remove_from_start();
    }

    int front() {
        return linkedList.front();
    }

    int back() {
        return linkedList.last();
    }
};


int main(){
    Deque obj;

    obj.push_back(4);
    obj.push_back(5);
    obj.push_back(10);

    cout<< obj.front() << "\n";
    cout<< obj.back() << "\n";

    obj.pop_front();
    obj.pop_back();

    cout<< obj.front() << "\n";
    cout<< obj.back() << "\n";

    return 0;
}