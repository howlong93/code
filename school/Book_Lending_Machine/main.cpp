#include <iostream>
#include "files.h"

using namespace std;

void CleanScreen() {
#ifdef _WIN32
    system("cls");                                                              
#else 
    system("clear");
#endif
}

void output_format(Linked_List *on_shelf) {
	CleanScreen();
	cout << string (75, '=') << '\n';
	cout << "1. Add new book on shelf\n"
		 << "2. Borrow book\n"
		 <<	"3. Return book\n"
		 <<	"4. Find book (by bookname)\n"
		 <<	"5. Print available books\n"
		 << "6. exit\n";

	cout << string (75, '=') << "\n\n" << "Current List >> \n\n";
	on_shelf -> Print_List();
	cout << string (75, '=') << "\n\n";
	cout << "服務項目選擇(1~5) : ";
}

int main() {
	CleanScreen();

	int n;
	Linked_List *on_shelf = new Linked_List();
	Linked_List *borrowed = new Linked_List();

	cerr << "original book amount: ";
	cin >> n;
	cin.ignore();

	cerr << '\n';
	for (int i = 0; i < n; i++) {
		on_shelf -> push_back ();
		cout << '\n';
	}

	on_shelf -> Print_List();

	cerr << "Press [enter] to continue\n";
	if (getchar() == '\n') {;}

	int ch;
	string x, y; 
	output_format(on_shelf);

	while (cin >> ch) {
		cin.ignore();
		CleanScreen();

		if (ch == 6) break;

		cerr << string(75, '~') << "\n\n";

		if (ch == 1) { //insert new book to shelf
			on_shelf -> Print_List();
			cerr << "\n" << string(75, '~') << '\n';

			cerr << "where do you want to put the new book?\n"
				 << "insert before (book id): ";
			cin >> x;
			cin.ignore();

			on_shelf -> insert (x, borrowed);
		}
		else if (ch == 2) { //borrow book
			on_shelf -> Print_List();
			cerr << string(75, '~') << '\n';
			cerr << "which book do you want to borrow?\n>> book name: ";
			getline (cin, x);
			
			Node *temp = on_shelf -> name_fnd_pos (x);
			if (temp != nullptr) {
				borrowed -> push_back (temp);
				on_shelf -> remove (x, 1);
				cerr << "\nBorrow " << temp -> book_name << " >> status: success\n";
			}
			else if (borrowed -> name_fnd_pos (x) != nullptr) {
				cerr << "lent out >> \n";
				borrowed -> query_book_name (x, 0);
			}
			else {
				cerr << "No such book: " << x << '\n';
			}
		}
		else if (ch == 3) { //return book
			cerr << "Borrowed books >>\n";
			borrowed -> Print_List();
			cerr << string (75, '~') << '\n';

			cerr << "Returning borrowed book.\n>> book id: ";
			cin >> x;
			cin.ignore();

			Node *temp = borrowed -> id_fnd_pos (x);
			if (temp != nullptr) {
				on_shelf -> push_back (temp);
				borrowed -> remove (x, 0);
				cout << "\n" << temp -> book_name << " returned successfully\n";
			}
			else {
				cout << "Not a lent out book: " << x << '\n';
			}
		}
		else if (ch == 4) {  //find book by name
			cerr << "which book do you want to find?\n>> book name: ";
			getline (cin, x);

			on_shelf -> query_book_name (x, 1);
			cerr << '\n';
			borrowed -> query_book_name (x, 0);
		}
		else if (ch == 5) {  //print list
			on_shelf -> Print_List();
			cerr << string (75, '~') << '\n';
		}

		cerr << "\npress [enter] to continue\n";
		if (getchar() == '\n') {;}

		output_format(on_shelf);
	}

	return 0;
}
