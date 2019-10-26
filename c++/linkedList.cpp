#include <bits/stdc++.h>

using namespace std;



class List{
	public:
	struct Node
		{
			int data;
			Node *next;
		};
			Node *head, *tail;
	List(){
			head = NULL;
			tail = NULL;
		}

};

void createList(int val){
	Node *node = new Node;
	node->data = val;
	node->next = NULL;

	if(head == NULL){
		head = node;
		tail = node;
		node = NULL;
	}
	else{
		tail->next = node;
		tail = node;
	}
}

void insertFront(int val){
	Node *node = new Node;
	node->next = head;
	head = node;
	node->data = val;
}

void insertBack(int val){
	Node *node = new Node;
	tail->next = node;
	tail = node;
}

void insert_with_index(int ind, int val){
    Node *prev = new Node;
    Node *cur = new Node;
    Node *node = new Node;

    cur = head;

    for(int i = 1; i < ind; i++){
    	prev = cur;
    	cur = cur->next;
    }
    node->data = val;
    prev->next = node;
    node->next = cur;
}

void print(){
	Node *node = new Node;
	node = head;
	while(node != NULL){
		cout << node->data << " ";
		node = node->next;
	}
}

void deleteFront(){
	Node *node = new Node;
	head = head->next;
	delete node;
}

void delete_with_index(int ind){
	Node *cur = new Node;
	Node *prev = new Node;
	cur = head;
	for(int i = 1; i < ind; i++){
		prev = cur;
		cur = cur->next;
	}
    prev->next = cur->next;
}

void deleteBack(){
	Node *prev = new Node;
	Node *cur = new Node;
	cur = head;
	while(cur->next != NULL){
		prev = cur;
		cur = cur->next;
	}
	tail = prev;
	prev->next = NULL;
	delete cur;

}
int main(){
	createList(1);
	insertBack(2);
	print();

	return 0;
}