#include <fstream>
#include <iostream>

using namespace std;

string fix_cin (string s, int pos) {
	int cnt_quot = 0;
	string ret;

	size_t i = 0;
	for (i = 0; i < pos; i++) ret += s[i];
	for (i = pos+3; i < s.size(); i++)
		if (s[i] != ' ') break;
	ret += "cin ";
	for ( ; i < s.size(); i++) {
		if (s[i] == '"') cnt_quot ^= 1;
		if (cnt_quot == 1) {
			ret += s[i];
			continue;
		}
		if (s[i] == '<' && s[i+1] == '<') ret += ">>", i++;
		else ret += s[i];
	}
	return ret;
}

string fix_cout (string s, int pos) {
	int cnt_quot = 0;
	string ret;

	size_t i = 0;
	for (i = 0; i < pos; i++) ret += s[i];
	for (i = pos+4; i < s.size(); i++)
		if (s[i] != ' ') break;
	ret += "cout ";
	for ( ; i < s.size(); i++) {
		if (s[i] == '"') cnt_quot = cnt_quot ^ 1;
		if (cnt_quot == 1) {
			ret += s[i];
			continue;
		}
		if (s.substr(i, 2) == ">>") ret += "<<", i++;
		else ret += s[i];
	}
	return ret;
}

int main() {
	ifstream input;
	ofstream output;
	string file_name;

	cout << "input filename: ";
	cin >> file_name;

	input.open(file_name);
	output.open("output.txt");
	if (input.fail()) {
		cout << "file opening error!!\n";
		return 0;
	}

	string temp;
	while (getline(input, temp)) {
		bool flag = false;
		for (size_t i = 0; i < temp.size(); i++) {
			if (i+3 < temp.size() && temp.substr(i, 3) == "cin" &&
				(temp[i+3] == ' ' || temp[i+3] == '<' || temp[i+3] == '>')) {
				output << fix_cin(temp, i) << '\n';
				flag = true;
				break;
			}
			else if (i+3 < temp.size() && temp.substr(i, 4) == "cout") {
				output << fix_cout(temp, i) << '\n';
				flag = true;
				break;
			}
		}
		if (!flag) output << temp << '\n';
	}
	input.close();
	output.close();

	return 0;
}
