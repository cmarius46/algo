#include <iostream>

//using namespace std;

struct node {
	int val;
	node* next;

	node(int v) {
		val = v;
		next = NULL;
	}

};


int main() {
	node* head = new node(0);
	node* currentNode = head;

	for(int i = 1; i <= 300; ++i) {
		node* newNode = new node(i);
		currentNode->next = newNode;
		currentNode = currentNode->next;
	}

	int k;
	std::cin >> k;

	node* lastNode = head;
	currentNode = head;

	for(int i = 0; i < k && lastNode != NULL; ++i) {
		lastNode = lastNode->next;
	}

	

	while(lastNode != NULL) {
		std::cout << lastNode->val << " " << currentNode->val << '\n';
		lastNode = lastNode->next;
		currentNode = currentNode->next;
	}

	std::cout << currentNode->val;


	return 0;
}