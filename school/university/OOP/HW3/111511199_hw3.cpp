#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string *addEntry (string *arr, int &size, string newEntry) {
	string *temp = new string[size+1];
	for (int i = 0; i < size; i++) temp[i] = arr[i];
	temp[size] = newEntry;
	size++;
	return temp;
}

string *deleteEntry (string *arr, int &size, string del_entry, ofstream &output) {
	string *temp = new string[size];
	bool found = false;
	int pos = 0;
	for (int i = 0; i < size; i++) {
		if (!found && del_entry == arr[i]) {
			found = true;
			continue;
		}
		temp[pos++] = arr[i];
	}

	if (!found) {
		output << "null\n";
	}
	else size--;

	return temp;
}
	
int main(int argc, char *argv[]) {
	string *arr, ch, param;
	int size = 0, num_of_oper;

	ifstream input;
	ofstream output;

	input.open(argv[1]);
	output.open(argv[2]);
	input >> num_of_oper;
	for (int i = 0; i < num_of_oper; i++) {
		input >> ch >> param;
		if (ch == "add") {
			arr = addEntry (arr, size, param);
		}
		else if (ch == "delete") {
			arr = deleteEntry (arr, size, param, output);
		}
	}

	output << '\n' << size << "\n";
	for (int i = 0; i < size; i++) {
		output << arr[i] << '\n';
	}

	input.close();
	output.close();

	return 0;
}
