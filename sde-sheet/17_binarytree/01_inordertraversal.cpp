/*
    Problem Statement: Given a Binary Tree. Find and print the inorder
    traversal of Binary Tree.

    <-- Iterative --> O(n) O(n)
    - while(true)
    - if(node!=NULL) push to stack and node=node->left
    - else
        - if(stack.isempty()) break;
        - else print top(), pop() and node=node->right.
 */

#include <bits/stdc++.h>
using namespace std;

struct node {
	int data;
	struct node * left, * right;
};

vector<int> inOrderTrav(node * curr) {
	vector<int> inOrder;
	stack<node*> s;
	while (true) {
		if (curr != NULL) {
			s.push(curr);
			curr = curr->left;
		} else {
			if (s.empty()) break;
			curr = s.top();
			inOrder.push_back(curr->data);
			s.pop();
			curr = curr->right;
		}
	}
	return inOrder;
}

struct node * newNode(int data) {
	struct node * node = (struct node * ) malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

// recursive method O(n) O(n)

void inOrderTrav(node * curr, vector < int > & inOrder) {
	if (curr == NULL)
		return;

	inOrderTrav(curr->left, inOrder);
	inOrder.push_back(curr->data);
	inOrderTrav(curr->right, inOrder);
}

int main() {
	struct node * root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->left->right->left = newNode(8);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->right->right->left = newNode(9);
	root->right->right->right = newNode(10);

	vector < int > inOrder;
	inOrderTrav(root, inOrder);

	cout << "The inOrder Traversal is : ";
	for (int i = 0; i < (int)inOrder.size(); i++) {
		cout << inOrder[i] << " ";
	}
	return 0;
}
