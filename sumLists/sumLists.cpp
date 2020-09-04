#include <iostream>

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


	Node* head1;
	Node* head2;

	int len1, len2;
	std::cin >> len1;

	if(len1 > 0) {
		int x;
		std::cin >> x;
		head1 = new Node(x);
		Node* currentNode = head1;
		for(int i = 1; i < len1; ++i) {
			std::cin >> x;
			Node* newNode = new Node(x);
			currentNode->next = newNode;
			currentNode = currentNode->next;
		}
	}

	std::cin >> len2;
	if(len2 > 0) {
		int x;
		std::cin >> x;
		head2 = new Node(x);
		Node* currentNode = head2;
		for(int i = 1; i < len2; ++i) {
			std::cin >> x;
			Node* newNode = new Node(x);
			currentNode->next = newNode;
			currentNode = currentNode->next;
		}
	}

	Node* head;

	if(len1 && len2) {
		int aux = 0;
		Node* nodeInFirst = head1;
		Node* nodeInSecond = head2;

		aux = (head1->val+head2->val)/10;
		head = new Node ((head1->val + head2->val)%10);

		nodeInFirst = nodeInFirst->next;
		nodeInSecond = nodeInSecond->next;

		Node* currentNode = head;

		while(nodeInFirst != NULL && nodeInSecond != NULL) {
			int sum = nodeInFirst->val + nodeInSecond->val + aux;
			Node* newNode = new Node(sum%10);
			aux = sum/10;
			currentNode->next = newNode;
			currentNode = currentNode->next;
		}
		while(nodeInFirst != NULL) {
			Node* newNode = new Node(nodeInFirst->val);
			currentNode->next = newNode;
			currentNode = currentNode->next;
		}

		while(nodeInSecond != NULL) {
			Node* newNode = new Node(nodeInSecond->val);
			currentNode->next = newNode;
			currentNode = currentNode->next;
		}
	}

	Node* currentNode = head;
	while(currentNode != NULL) {
		std::cout << currentNode->val << " ";
		currentNode = currentNode->next;
	}


	return 0;
}