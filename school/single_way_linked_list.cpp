#include <stdio.h>
#include <stdlib.h>

struct Node {
	Node() { // (Node*) malloc (sizeof(Node)) 時初始化
		next = NULL;
		val = 0;
	}
	int val;
	Node *next; //下一個
};

Node *head;

void Print_List();
void push_back(int x);
void insert (Node *pos, int x);
void remove (Node *pos);

int main() {
	int n;
	while (scanf ("%d", &n) != EOF) {
		if (n == 0) {
			int x;
			scanf ("%d", &x);
			push_back (x);
		}
		else if (n == 1) {
			int x, y;
			scanf ("%d %d", &x, &y);
			Node *temp = head;
			while (temp != nullptr && temp -> val != x) temp = temp -> next;
			if (temp != NULL) insert (temp, y);
		}
		else if (n == 2) {
			int x;
			scanf ("%d", &x);
			Node *temp = head;
			while (temp != NULL && temp -> val != x) temp = temp -> next;
			if (temp != NULL) remove (temp);
		}
		else if (n == 3) Print_List();
		Print_List();
	}
	return 0;
}

//輸出整個 linked list
void Print_List() {
	Node *cur = head;
	while (cur != NULL) {
		printf ("%d ", cur -> val);
		cur = cur -> next;
	}
	printf("\n");

	return;
}

//放 x 到最後面
void push_back (int x) {
	Node *temp = (Node*) malloc (sizeof(Node));
	temp -> val = x;
	temp -> next = NULL;

	if (head == NULL) { //目前是空的
		head = temp;
	}
	else {
		Node *cur = head;
		while (cur -> next != NULL) cur = cur -> next; //找到最後一個節點

		cur -> next = temp;
	}
}

//插在pos的前一個位置
void insert (Node *pos, int x) {
	// pos = b
	// 原本：a -> b  >> insert(b) >> a -> x -> b
	
	Node *temp = (Node*) malloc (sizeof(Node)), *prev = head;
	temp -> val = x;

	if (pos == head) { // pos 是開頭 (head)
		temp -> next = head;
		head = temp;
	}
	else {
		while (prev -> next != pos) prev = prev -> next;

		temp -> next = pos;               // x -> next = b;
		prev -> next = temp;              // b -> prev = x;
	}
}

//移除pos的節點
void remove (Node *pos) {
	if (pos == NULL) return;
	Node *prev = head;

	while (prev != pos && prev -> next != pos) prev = prev -> next;

	if (pos == head) { // pos 是開頭 pos(r) -> b -> c...
		head = head -> next;      // pos -> b(r) -> c
		delete pos;               // b(r) -> c
	}
	else if (pos -> next == NULL) {  // pos 是結尾 .. -> b -> pos
		prev -> next = NULL;			// .. -> b     pos
		delete pos;
	}
	else {								// pos 是中間的  ... a -> pos -> b ...
		prev -> next = pos -> next;
		delete pos;
	}

	return;
}
