#include <iostream>

struct node {
	int val;
	node* next;

	node(int val) {
		this->val = val;
		next = NULL;
	}
};

int main() {

	node* head = new node(0);
	node* currentNode = head;
	node* inputNode;

	for(int i = 1; i < 31; ++i){
		node* newNode = new node(i);
		currentNode->next = newNode;
		currentNode = currentNode->next;

		if(i == 16) {
			inputNode = currentNode;
		}
	}


	currentNode = head;
	/*
	while(currentNode != NULL) {
		std::cout << currentNode->val << " ";
		currentNode = currentNode->next;
	}
	*/

	currentNode = inputNode;

	while(currentNode->next != NULL) {
		currentNode->val = currentNode->next->val;
		if(currentNode->next->next == NULL) {
			node* aux = currentNode->next;
			currentNode->next = NULL;
			currentNode = aux;
		}
		else {
			currentNode = currentNode->next;	
		}
	}

	delete[] currentNode;

	currentNode = head;
	while(currentNode != NULL) {
		std::cout << currentNode->val << " ";
		currentNode = currentNode->next;
	}


	return 0;
}