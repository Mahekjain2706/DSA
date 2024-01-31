#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    ~Node(){
        int val = this->data;
        if(this->next !=NULL){
            delete next;
            this->next = NULL;
        }
        cout<< " Memory is free for node with data " << val << endl;
    }
};

void InsertAtHead(Node* &head,int d){

    // new node create
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void InsertAtTail(Node* &head,int d){
    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    Node* insertNode = new Node(d);
    temp->next = insertNode;
}
// insert at position
void InsertAtposition(Node* &head,int posi,int d){
    if(posi==1){
        InsertAtHead(head,d);
        return;
    }
    Node* temp = head;
    int cnt=1;
    while(cnt!=posi-1){
        temp = temp->next;
        cnt++;
    }
    if(temp->next == NULL){
        InsertAtTail(head,d);
        return;
    }
    Node* InsertNode = new Node(d);
        InsertNode->next = temp->next;
        temp->next= InsertNode;
}
// insert by value
void InsertbyValue(Node* &head,int val,int d){
   Node* temp = head;

   while(temp->data != val){
    temp = temp->next;
   }
   Node* insertNode = new Node(d);
   if(temp->next==NULL){
      temp->next = insertNode;
      return;
   }
   insertNode->next = temp->next;
   temp->next = insertNode;
}

// Deletion
void deleteNode(int posi, Node* &head){

    //deleting first or start node
    if(posi == 1){
        Node* temp = head;
        head = head->next;
        // memory free
        temp->next = NULL;
        delete(temp);
    }
    else{
    Node* curr = head;
    Node* prev = NULL;
    int cnt =1;
    while(cnt< posi){
        prev = curr;
        curr = curr->next;
        cnt++;
    }

    prev ->next = curr->next;
    curr->next = NULL;
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

    Node* node = new Node(1);
    Node* head = node;
    // insert at head
    InsertAtHead(head,2);
    print(head);

    // insert at tail
    InsertAtTail(head,0);
    print(head);

    // insert at tail
    InsertAtposition(head,4,3);
    print(head);
    // insert at head
    InsertAtposition(head,1,5);
    print(head);
    // insert at position
    InsertAtposition(head,3,6);
    print(head);
    // insert at postion
    InsertbyValue(head,2,7);
    print(head);
    // insert at end
    InsertbyValue(head,3,8);
    print(head);
    deleteNode(2 , head);
    print(head);

    return 0;
}