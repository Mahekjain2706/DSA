#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* next;

    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

class LinkList{
    private:
    Node* head;

    public:
    
    LinkList() : head(NULL){};

    ~LinkList(){
        Node* curr = head;
        Node* nextN = NULL;

        while(curr!=NULL){
            nextN = curr->next;
            delete curr;
            curr = nextN;
        }
        head = NULL;
    }
    void insert_at_start(int num){
        if(head==NULL){
            Node* insertNode = new Node(num);
            head = insertNode;
            return;
        }
        Node* newN = new Node(num);
        newN->next = head;
        head = newN;
    }

    void remove_from_start(){
        if(head==NULL) return;
        Node* removeN = head;
        head = head->next;
        delete removeN;
    }

    void insert_at_end(int num){
        Node* newN = new Node(num);
        if(head==NULL){
            head = newN;
        }
        Node* curr = head;
        while(curr->next!=NULL){
            curr = curr->next;
        }
        curr->next = newN;
    }

    void remove_from_end(){
        if(head==NULL) return;
        else if(head->next==NULL){
            delete head;
            head = NULL;
            return;
        }
        Node* prev = NULL;
        Node* curr = head;
        while(curr->next!=NULL){
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
        delete curr;
    }

    int front(){
        if(head==NULL) return 0;
        return head->val;
    }

    int last(){
        if(head==NULL) return 0;
        Node* curr = head;
        while(curr->next!=NULL){
            curr = curr->next;
        }
        return curr->val;
    }

    void traverse(){
        if(head==NULL) return;
        Node* curr = head;
        while(curr!=NULL){
            cout<< curr->val << " ";
            curr = curr->next;
        }
        cout<< endl;
    }
};

int main(){
    // node = new Node(1);
    LinkList obj ;
    obj.insert_at_start(1);
    obj.traverse();
    obj.insert_at_end(2);
    obj.traverse();
    obj.insert_at_start(3);
    obj.traverse();
    obj.insert_at_end(4);
    obj.traverse();
    
    cout<< obj.front() << " "<<obj.last()<<"\n";

    obj.remove_from_start();
    obj.traverse();
    obj.remove_from_end();
    obj.traverse();

    return 0;
}