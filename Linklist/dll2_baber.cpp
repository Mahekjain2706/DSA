#include<iostream>
using namespace std;

class Node{
    public: 
    int data;
    Node* prev;
    Node* next;

    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node(){
      int data = this->data;
      if(this->next!=NULL){
        delete next;
        this->next = NULL;
      }
      cout<< " Memory is free for node with data " << data << endl;
    }
};

void insertAtHead(Node* &head,int d){
    Node* insert = new Node(d);
    insert->next = head;
    head->prev = insert;
    head = insert;
}

void insertAtTail(Node* head,int d){
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    Node* insert = new Node(d);
    temp->next = insert;
    insert->prev = temp;
}

void insertAtposition(Node* &head,int posi,int d){

    // insert at start
    if(posi == 1){
        insertAtHead(head,d);
        return;
    }
    Node* temp = head;
    int cnt = 1;

    while( cnt < posi-1){
        temp = temp->next;
        cnt++;
    }

    Node* nodeToinsert =new Node(d);
    nodeToinsert -> next = temp->next;
    temp->next->prev = nodeToinsert;
    temp->next = nodeToinsert;
    nodeToinsert->prev = temp;
}

//deletion 
void deleteNode(Node* &head,int posi){
    if(posi==1){
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next=NULL;
        delete(temp);
    }
    else{
        int cnt=1;
        Node* curr = head;
        Node* pre = NULL;
        
        while(cnt<posi){
            pre = curr;
            curr=curr->next;
            cnt++;
        }
        if(curr->next==NULL){
            pre->next=NULL;
            curr->prev=NULL;
            delete(curr);
            return;
        }
        pre->next = curr->next;
        curr->next->prev = curr->prev;
        curr->next=NULL;
        curr->prev=NULL;
        delete(curr);
    }
}

void print(Node* &head){
    Node* temp = head;

    while(temp !=NULL){
        cout<< temp->data << " ";
        temp = temp->next;
    }
    cout<< endl;
}

int getLength(Node* &head){
    int len=0;
    Node* temp = head;

    while(temp !=NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

int main(){

    Node* node = new Node(1);
    Node* head = node;

    // print(head);
    // cout<< getLength(head) << endl;

    insertAtHead(head,2);
    print(head);

    insertAtTail(head,3);
    print(head);
    
    insertAtposition(head,4,4);
    print(head);

    deleteNode(head,4);
    print(head);
    
    deleteNode(head,1);
    print(head);

    return 0;
}