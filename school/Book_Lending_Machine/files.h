#include <iostream>

using namespace std;

struct Node {
	string book_id;
	string book_name;
//	string time;

	Node *next;
	Node *prev;

	Node() {
		next = prev = nullptr;
		book_name = "";
		book_id = "0000";
	}

	Node (string id, string nm) {
		next = prev = nullptr;
		book_name = nm;
		book_id = id;
	}
};

struct Linked_List {
  private:

	Node *root;
	unsigned int aba;

  public:

	Linked_List () {
		root = nullptr;
		aba = 0;
	}
	Linked_List (Node *r) {
		root = r;
		aba = 1;
	}

	//TODO
	void Print_List() {
		Node *cur = root;
	    while (cur != nullptr) {
		    cout << cur -> book_id << " - " << cur -> book_name << '\n';
			cur = cur -> next;
	    }
		cout << '\n';
	}
	
	unsigned int get_lnth () {
		return aba;
	}

	Node* input_data() {
		Node *ret = new Node();
		
		cerr << "new book id: ";
		cin >> ret -> book_id;
		cin.ignore();

		cerr << "book name: ";
		getline (cin , ret -> book_name);

		return ret;
	}

	Node* id_fnd_pos (string id) {
		Node *tmp = root;
		while (tmp != nullptr) {
			if (tmp -> book_id == id) return tmp;
			tmp = tmp -> next;
		}
		return nullptr;
	}

	Node* name_fnd_pos (string name) {
		Node *tmp = root;
		while (tmp != nullptr) {
			if (tmp -> book_name == name) return tmp;
			tmp = tmp -> next;
		}
		return nullptr;
	}

	void query_book_name (string name, bool choice) {
		Node *tmp = root;
		
		cerr << '\n' << (choice ? "available >>" : "borrowed >>") << '\n';
		if (name_fnd_pos(name) == nullptr) {
			cerr << name << ": Not found ";
			cerr << (choice ? "on shelf\n" : "in borrowed list\n");
		}			

		int cnt = 1;
		while (tmp != nullptr) {
			if (tmp -> book_name == name) {
				if (choice) cout << "pos: " << cnt << " >> ";
				cout << tmp -> book_id << " - " << tmp -> book_name << '\n';
			}
			if (choice) cnt++;
			tmp = tmp -> next;
		}
		return;
	}

	void push_back () {
		Node *temp = input_data();

	    if (root == nullptr) {
		    root = temp;
	    }
		else if (id_fnd_pos (temp -> book_id) != nullptr) {
			cerr << "duplicate book!!\n";
			return;
		}
		else {
			Node *cur = root;
	        while (cur -> next != nullptr) cur = cur -> next;

		    temp -> prev = cur;
			cur -> next = temp;
	    }
		aba++;
	}

	void push_back (Node *data) {
		Node *temp = new Node(data -> book_id, data -> book_name);

		if (root == nullptr) {
			root = temp;
		}
		else if (id_fnd_pos (temp -> book_id) != nullptr) {
			cerr << "already in list!\n";
			return;
		}
		else {
			Node *cur = root;
			while (cur -> next != nullptr) cur = cur -> next;

			temp -> prev = cur;
			cur -> next = temp;
		}
		aba++;
	}

	void insert (string tar_id, Linked_List* bor) {
		Node *pos = id_fnd_pos (tar_id);
		if (pos == nullptr) {
			cout << "ID: "<< tar_id << " not found\n";
			return;
		}

		cerr << '\n';
	    Node *temp = input_data();
		if (id_fnd_pos(temp -> book_id) != nullptr || bor -> id_fnd_pos (temp -> book_id) != nullptr) {
			cout << "\nunavailable ID: " << temp -> book_id << '\n';
			return;
		}

		if (pos -> prev == nullptr) {
		    temp -> next = root;
		    root -> prev = temp;
		    root = temp;
		}
		else {
		    temp -> prev = pos -> prev;
		    temp -> next = pos;
		    pos -> prev -> next = temp;
		    pos -> prev = temp;
		}
		aba++;

		cerr << "\nInsert " << temp -> book_name << " >> status: success\n";
	}
	
	void remove (string tar, bool method) { // borrow & return
		Node *pos = nullptr;

		if (method) { // borrow book (find by name)
			pos = name_fnd_pos (tar);
		}
		else { // return book (find by id)
			pos = id_fnd_pos (tar);
		}

		if (pos == nullptr) {
			cout << "No book " << tar <<  "!!\n";
			return;
		}

		if (pos -> prev == nullptr && pos -> next == nullptr) {
			root = nullptr;
			delete pos;
		}
		else if (pos -> prev == nullptr) { 
			root = root -> next;
			root -> prev = nullptr;
			delete pos;
		}
		else if (pos -> next == nullptr) {
			pos -> prev -> next = nullptr;
			delete pos;
		}
		else {
			pos -> prev -> next = pos -> next;
			pos -> next -> prev = pos -> prev;
			delete pos;
		}
		aba--;
	}
};
