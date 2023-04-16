#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class DecimalBookInfo {
  private:
    float _code;
    string _book;
  public:
    DecimalBookInfo (string book, float code) {
        _book = book;
        _code = code;
    }

    void friend PrintBooks (const vector<DecimalBookInfo> &list);

    bool operator< (DecimalBookInfo x) {
        return _code < x._code;
    }

    bool operator<= (DecimalBookInfo x) {
        return _code <= x._code;
    }

    bool operator> (DecimalBookInfo x) {
        return _code > x._code;
    }

    bool operator>= (DecimalBookInfo x) {
        return _code >= x._code;
    }
};

void PrintBooks(const vector<DecimalBookInfo> &list) {
    int hund = 0;

    for (size_t i = 0; i < list.size(); i++) {
        if ((int) list[i]._code/100 > hund) {
            hund = (int) list[i]._code/100;
            cout << "SubjectNum: " << hund << '\n';
        }
        cout << list[i]._book << ' ' << list[i]._code << '\n';
    }
}

int main() {
    vector<string> NameLists = {"The Elements of Chemistry",
                                "Chemical Principles",
                                "Computer Organization and Design",
                                "The C++ Programming Language",
                                "The Wealth of Nations",
                                "The Story of Art",
                                "The Origin of Species",
                                "ABC"};
    vector<float> CodeLists = {516.3, 563.4, 490.3, 490.6,
                               830.7, 120.9, 259.8, 259.8};
    vector<DecimalBookInfo> BookLists;
    for (int i = 0; i < (int)CodeLists.size(); i++) {
        DecimalBookInfo temp(NameLists[i], CodeLists[i]);
        BookLists.push_back(temp);
    }
    sort(BookLists.begin(), BookLists.end());
    PrintBooks(BookLists);
    cout << "\n";

    if (BookLists[3] > BookLists[2])
        cout << "true\n";
    else
        cout << "false\n";

    if (BookLists[3] < BookLists[2])
        cout << "true\n";
    else
        cout << "false\n";

    if (BookLists[1] >= BookLists[2])
        cout << "true\n";
    else
        cout << "false\n";

    if (BookLists[1] <= BookLists[2])
        cout << "true\n";
    else
        cout << "false\n";
}
