#include <iostream>
#include <vector>

//using namespace std;

struct Node {
	int val;
	Node* next;

	Node() {
		next = NULL;
	}
	Node(int val) {
		this->val = val;
		this->next = NULL;
	}
};

int main() {

	int n;
	std::cin >> n;
	int x;

	Node* head;

	if(n > 0) {
		std::cin >> x;
		head = new Node(x);
	}

	Node* currentNode = head;
	for(int i = 1; i < n; ++i) {
		std::cin >> x;
		Node* newNode = new Node(x);
		currentNode->next = newNode;
		currentNode = currentNode->next;
	}

	currentNode = head;
	/*
	while(currentNode != NULL) {
		std::cout << currentNode->val << " ";
		currentNode = currentNode->next;
	}
	*/

	std::cin >> x;

	std::vector<int> smaller;
	std::vector<int> bigger;
	while(n && currentNode != NULL) {
		if(currentNode->val < x) {
			smaller.push_back(currentNode->val);
		}
		else {
			bigger.push_back(currentNode->val);
		}
		currentNode = currentNode->next;
	}

	currentNode = head;
	for(auto i : smaller) {
		currentNode->val = i;
		currentNode = currentNode->next;
	}

	for(auto i : bigger) {
		currentNode->val = i;
		currentNode = currentNode->next;
	}


	currentNode = head;
	while(n && currentNode != NULL) {
		std::cout << currentNode->val << " ";
		currentNode = currentNode->next;
	}


	return 0;
}