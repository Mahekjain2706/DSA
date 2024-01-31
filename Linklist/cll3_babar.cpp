#include<iostream>
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
        int val = data;
        if(this->next != NULL){
           delete next;
           next = NULL;
        }
        cout<< "memeory is free for node with data " << val << endl;
    }
};

void InsertNode(Node* &tail,int element, int d){
    
    // empty list
    if(tail == NULL){
       Node* newNode = new Node(d);
       tail = newNode;
       newNode->next = newNode;
    }
    else{
    // non-empty list
    // assuming that the element is present in the list

       Node* curr = tail;

       while(curr->data != element){
        curr = curr->next;
       }

       // element found -> curr is representing element wala node
       Node* temp = new Node(d);
       temp->next = curr->next;
       curr->next = temp;

    } 
}

void deletionNode(Node* &tail,int value){

    // empty list
    if(tail==NULL){
        cout<< "list is empty. "<< endl;
        return;
    }
    else{
        // non-empty

        // assuming the value "value" is present in the ll
        Node* prev = tail;
        Node* curr = prev->next;

        while(curr->data != value){
            prev =curr;
            curr = curr->next;
        }

        prev->next = curr->next;

        // 1 node lisklist
        if(curr == prev ){
           tail = NULL;
        }

        // >=2 link list
        if(tail== curr){
            tail = prev;
        }
        curr->next = NULL;
        delete curr;

    }
}

void print(Node* &tail){
    Node* temp = tail;
    
    // cout << tail->data << " ";
    // // nodes>1
    // while(tail->next != temp){
    //     cout<< tail ->data << " ";
    //     tail = tail->next;
    // }
    // cout<< endl;
    if(tail == NULL){
        cout<< "List is Empty "<< endl;
        return;
    }

    do{
        cout<< tail->data << " ";
        tail = tail->next;
    }while(tail !=temp);
    cout<< endl;
}

int main(){
    Node* tail = NULL;

    InsertNode(tail,5,3);
    print(tail);
    InsertNode(tail,3,5);
    print(tail);
    // InsertNode(tail,5,7);
    // print(tail);
    // InsertNode(tail,7,9);
    // print(tail);
    // InsertNode(tail,5,6);
    // print(tail);
    // InsertNode(tail,9,10);
    // print(tail);
    // InsertNode(tail,3,4);
    // print(tail);
    deletionNode(tail,3);
    print(tail);

    return 0;
}