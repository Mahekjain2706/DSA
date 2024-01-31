#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node* next;
    Node* prev;
    int data;

    Node(int d){
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }

    ~Node(){
        int val = this->data;
        if(this->next!=NULL){
            delete(next);
            this->next=NULL;
        }
        cout<< "Mmemory is free at index with val: "<< val << endl;
    }
};


void insertAtHead(Node* &head,int d){
    if(head==NULL){
        Node* node = new Node(d);
        head = node;
        return;
    }
    Node* node = new Node(d);
    node->next = head;
    head->prev = node;
    head = node;
    return;
}
void insertAtTail(Node* &head,int d){
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    Node* node = new Node(d);
    temp->next = node;
    node->prev = temp;
}
void insertAtposition(Node* &head,int posi,int d){
    if(posi==1){
        insertAtHead(head,d);
        return;
    }else{
        Node* curr = head;
        int cnt = 1;
        while(cnt<posi-1){
            curr = curr->next;
            cnt++;
        }
        if(curr->next==NULL){
            insertAtTail(head,d);
            return;
        }
        Node* node = new Node(d);
        node->next = curr->next;
        node->prev = curr;
        curr->next = node;
    }
}

void deleteNode(Node* &head,int posi){
    if(posi==1){
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        delete(temp);
    }
    else{
        Node* prev = NULL;
        Node* curr = head;
        int cnt = 1;
        while(cnt<posi){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        if(curr->next==NULL){
            prev->next = NULL;
            curr->prev = NULL;
            delete(curr);
            return;
        }
        prev->next = curr->next;
        curr->next->prev = curr->prev;
        curr->next = NULL;
        curr->prev = NULL;
        delete(curr);
    }
}


void print(Node* &head){
    Node* temp = head;
    while(temp!=NULL){
        cout<< temp->data << " ";
        temp = temp->next;
    }
    cout<< endl;
}
int main(){

    Node* head = NULL;

    insertAtHead(head,2);
    print(head);

    insertAtHead(head,1);
    print(head);

    insertAtTail(head,3);
    print(head);

    // cout<< head->next->next->prev->data << endl;

    insertAtposition(head,4,2);
    print(head);

    deleteNode(head,4);
    print(head);

    return 0;
}