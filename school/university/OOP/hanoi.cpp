#include <iostream>

using namespace std;

int op = 0;
string english[11] = {"zero", "first", "second", "third", "fourth", "fifth", "sixth"
					  "seventh", "eighth", "ninth", "tenth"};

void hanoi (char a, char b, char c, int num) {
	if (num <= 0) return;
	hanoi (a, c, b, num-1);
	cout << "move "<< english[num] << " plate from " << a << " to " << c << '\n';
	op++;
	hanoi (b, a, c, num-1);
	return;
}

int main() {
	int num;
	cout << "number of plates: ";
	cin >> num;

	hanoi ('A', 'B', 'C', num);

	cout << "\nNeed to move " << op << " times\n";

	return 0;
}
