#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
	Node* next;
	int data;

	Node(int val){
		this->data = val;
		this->next = NULL;
	}
	
	~Node(){
		int val = this->data;
		if(this->next!=NULL){
			delete(next);
			this->next=NULL;
		}
		cout<< "Memory is free from the node with val: " << val << endl;
	}
};

// insert
void insertAtHead(Node* &head,int d){
	if(head==NULL){
		Node* node = new Node(d);
		head = node;
		return;
	}
	
	Node* node = new Node(d);
	node->next = head;
	head = node;
}

void insertAtTail(Node* &head,int d){
	
	Node* temp = head;
	while(temp->next !=NULL){
		temp = temp->next;
	}
	Node* node = new Node(d);
	temp->next = node;
}


void insertAtposition(Node* &head,int posi,int d){
	if(posi==1){
		insertAtHead(head,d);
		return;
	}
	else{
		int cnt = 1;
		Node* temp = head;
		while(cnt<posi-1){
			temp = temp->next;
			cnt++;
		}
		if(temp->next==NULL){
			insertAtTail(head,d);
			return;
		}
		Node* node = new Node(d);
		node->next = temp->next;
		temp->next = node;
	}
}

// delete
void deleteNode(Node* &head,int posi){
	if(posi==1){
		Node* temp = head;
		head = head->next;
		temp->next = NULL;
		delete(temp);
		return;		
	}
	else{
		Node* prev = NULL;
		Node* curr = head;
		int cnt=1;
		while(cnt<posi){
			prev = curr;
			curr = curr->next;
			cnt++;
		}
		prev->next = curr->next;
		curr->next = NULL;
		delete(curr);
	}
}

// print
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

	insertAtTail(head,3);
	print(head);

	insertAtposition(head,1,1);
	print(head);

	insertAtposition(head,4,4);
	print(head);

	insertAtposition(head,3,3);
	print(head);

	deleteNode(head,4);
	print(head);

	return 0;
}