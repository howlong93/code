#include <iostream>

using namespace std;

struct Node {
	Node() { // new Node() 時初始化
		next = prev = nullptr;
		val = 0;
	}
	int val;
	Node *next; //下一個
	Node *prev; //前一個
};

Node *root;

void Print_List();
void push_back(int x);
void insert (Node *pos, int x);
void remove (Node *pos);

int main() {
	int n, c;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> c;
		push_back (c);
	}
	Print_List();

	// root 為第 1 個
	// linked list: r -> a -> b -> c
	//     編號   : 1    2    3    4
	int x, y, z;
	while (cin >> x) {
		Node *cur = root;
		if (x == 1) {        // insert z 到第 y 個
			cin >> y >> z;
			for (int i = 1; i < y; i++) cur = cur -> next; // 找到第 y 個
			insert (cur, z);
		}
		else if (x == 2) {   // remove 第 y 個
			cin >> y;
			for (int i = 1; i < y; i++) cur = cur -> next; // 找到第 y 個
			remove (cur);
		}
		else if (x == 3) {   // push_back (z)
			cin >> z;
			push_back (z);
		}
		else if (x == 4) {   // Print_List();
			Print_List();
		}
	}

	return 0;
}

//輸出整個 linked list
void Print_List() {
	Node *cur = root;
	while (cur != nullptr) {
		cout << cur -> val << ' ';
		cur = cur -> next;
	}
	cout << '\n';
}

//放 x 到最後面
void push_back (int x) {
	Node *temp = new Node();
	temp -> val = x;

	if (root == nullptr) { //目前是空的
		root = temp;
	}
	else {
		Node *cur = root;
		while (cur -> next != nullptr) cur = cur -> next; //找到最後一個節點

		temp -> prev = cur;
		cur -> next = temp;
	}
}

//插在pos的前一個位置
void insert (Node *pos, int x) {
	// pos = b
	// 原本：a -> b  >> insert(b) >> a -> x -> b
	
	Node *temp = new Node();
	temp -> val = x;
	if (pos -> prev == nullptr) { // pos 是開頭 (root)
		temp -> next = root;
		root -> prev = temp;
		root = temp;
	}
	else {
		temp -> prev = pos -> prev;      // x -> prev = a
		temp -> next = pos;              // x -> next = b;
		pos -> prev -> next = temp;      // a -> next = x;
		pos -> prev = temp;              // b -> prev = x;
	}
}

//移除pos的節點
void remove (Node *pos) {
	if (pos -> prev == nullptr) { // pos 是開頭 pos(r) -> b -> c...
		root = root -> next;      // pos -> b(r) -> c
		root -> prev = nullptr;   // pos    b(r) -> c
		delete pos;               // b(r) -> c
	}
	else if (pos -> next == nullptr) {   // pos 是結尾 .. -> b -> pos
		pos -> prev -> next = nullptr;  // .. -> b     pos
		delete pos;
	}
	else {                                 // pos 是中間的  ... a -> pos -> b ...
		pos -> prev -> next = pos -> next; // a 的 next 指向 b
		pos -> next -> prev = pos -> prev; // b 的 prev 指向 a
	}
}
