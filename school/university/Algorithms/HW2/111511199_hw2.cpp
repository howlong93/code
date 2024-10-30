#include <bits/stdc++.h>

using namespace std;

#define NIL -1e12
#define RED 0
#define BLACK 1

class Node {
  public:
	long long val;
	bool color;
	long long max_branch;
	Node *left, *right, *par;

	Node () {
		val = NIL;
		left = right = par = nullptr;
		max_branch = INT_MIN;
		color = BLACK;
	}

	Node (long long _val) {
		val = _val;
		left = right = par = nullptr;
		max_branch = INT_MIN;
		color = BLACK;
	}
};

Node* NIL_ptr = new Node;

Node *node(long long val = NIL) {
	if (val == NIL) return NIL_ptr;
	Node *ret = new Node (val);
	ret->left = ret->right = ret->par = NIL_ptr;

	return ret;
}

class RB_Tree {
  public:
	Node *root;
	long long max_path_sum;

	RB_Tree () {
		root = node();
		max_path_sum = INT_MIN;
	}

	void left_rotate (Node *x) {
		Node *y = x->right;
		x->right = y->left;
		if (y->left != NIL_ptr) y->left->par = x;
		y->par = x->par;

		if (x->par == NIL_ptr) root = y;
		else if (x == x->par->left) x->par->left = y;
		else x->par->right = y;

		y->left = x;
		x->par = y;

		return;
	}

	void right_rotate (Node *y) {
		Node *x = y->left;
		y->left = x->right;
		if (x->right != NIL_ptr) x->right->par = y;
		x->par = y->par;

		if (y->par == NIL_ptr) root = x;
		else if (y == y->par->left) y->par->left = x;
		else y->par->right = x;

		x->right = y;
		y->par = x;

		return;
	}

	void insert_fixup (Node *z) {
		Node *y = NIL_ptr;
		while (z->par->color == RED) {
			if (z->par == z->par->par->left) {
				y = z->par->par->right;
				if (y->color == RED) {
					z->par->color = BLACK;
					y->color = BLACK;
					z->par->par->color = RED;
					z = z->par->par;
				}
				else if (z == z->par->right) {
					z = z->par;
					left_rotate (z);
				}
				else { 
					z->par->color = BLACK;
					z->par->par->color = RED;
					right_rotate (z->par->par);
				}
			}
			else {
				y = z->par->par->left;
				if (y->color == RED) {
					z->par->color = BLACK;
					y->color = BLACK;
					z->par->par->color = RED;
					z = z->par->par;
				}
				else if (z == z->par->left) {
					z = z->par;
					right_rotate (z);
				}
				else {
					z->par->color = BLACK;
					z->par->par->color = RED;
					left_rotate (z->par->par);
				}
			}
		}
		root->color = BLACK;

		return;
	}

	void insert (Node *z) {
		Node *y = NIL_ptr, *x = root;
		while (x != NIL_ptr) {
			y = x;
			if (z->val < x->val) x = x->left;
			else x = x->right;
		}
		z->par = y;
		
		if (y == NIL_ptr) root = z;
		else if (z->val < y->val) y->left = z;
		else y->right = z;

		z->left = NIL_ptr;
		z->right = NIL_ptr;
		z->color = RED;

		insert_fixup(z);

		return;
	}

	void preorder_traverse (Node *cur) {
		if (cur == NIL_ptr) return;
		cout << cur->val << ' ';
		preorder_traverse (cur->left);
		preorder_traverse (cur->right);
		return;
	}
	void inorder_traverse (Node *cur) {
		if (cur == NIL_ptr) return;
		inorder_traverse (cur->left);
		cout << cur->val << ' ';
		inorder_traverse (cur->right);
		return;
	}

	long long fnd_max_branch (Node *cur) {
		if (cur == NIL_ptr) return INT_MIN;
		
		long long l = fnd_max_branch (cur->left);
		long long r = fnd_max_branch (cur->right);
		long long val = cur->val;

		return cur->max_branch = max ({val, val+l, val+r});
	}

	void fnd_max_path_sum (Node *cur) {
		if (cur == NIL_ptr) return;

		fnd_max_path_sum (cur->left);
		fnd_max_path_sum (cur->right);

		long long l = cur->left->max_branch, r = cur->right->max_branch;
		long long tmp = max ({cur->val, cur->val+l, cur->val+r, cur->val+l+r});

		max_path_sum = max (max_path_sum, tmp);

		return;
	}
};

int main () {
	NIL_ptr->left = NIL_ptr->right = NIL_ptr->par = NIL_ptr;
	RB_Tree T;

	long long node_val;
	while (cin >> node_val) {
		Node *tmp = node (node_val);
		T.insert (tmp);
	}

	T.preorder_traverse (T.root);
	cout << '\n';

	T.fnd_max_branch (T.root);
	T.fnd_max_path_sum (T.root);

	cout << T.max_path_sum << '\n';

	return 0;
}
