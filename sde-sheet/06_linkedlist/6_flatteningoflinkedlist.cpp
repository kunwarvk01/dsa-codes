/*

 */

#include <bits/stdc++.h>
using namespace std;
struct node {
public:
	int data;
	node* next;
	node* bottom;
	node(int val) {
		data = val;
		next = NULL;
		bottom = NULL;
	}
};

node* mergeTwoLists(node* a, node* b) {
	node *temp = new node(0);
	node *res = temp;

	while(a != NULL && b != NULL) {
		if(a->data < b->data) {
			temp->bottom = a;
			temp = temp->bottom;
			a = a->bottom;
		}
		else {
			temp->bottom = b;
			temp = temp->bottom;
			b = b->bottom;
		}
	}

	if(a) temp->bottom = a;
	else temp->bottom = b;

	return res->bottom;

}
node *flatten(node *root){
	if (root == NULL || root->next == NULL)
		return root;

	// recur for list on right
	root->next = flatten(root->next);

	// now merge
	root = mergeTwoLists(root, root->next);

	// return the root
	// it will be in turn merged with its left
	return root;
}
