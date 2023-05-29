#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

class Product {
  public:
    string type, name;
    int quantity;

    Product() {
        quantity = 0;
    }
    Product (string _t, string _n, int _q) {
        type = _t;
        name = _n;
        quantity = _q;
    }
};

int main(int argc, char *argv[]) {
    ifstream input;
    input.open (argv[1]);

    map<string, map<string, int>> data;
    vector<Product> vec;
    
    string pc_type, pc_nm;
    int i = 0;
    int quantity;
    while (input >> pc_type >> pc_nm >> quantity) {
        data[pc_type][pc_nm] = quantity;
        Product temp (pc_type, pc_nm, quantity);
    }

    string ch;
    while (cin >> ch) {
        if (ch == "-i") {
            cin >> pc_type >> pc_nm >> quantity;
            data[pc_type][pc_nm] += quantity;
            bool flag = false;
        }
        else if (ch == "-s") {
            cin >> pc_type >> pc_nm >> quantity;
            data[pc_type][pc_nm] -= quantity;
        }
        else if (ch == "-d") {
            cin >> pc_type >> pc_nm;
            cout << pc_type << ' ' << pc_nm << ' ' << data[pc_type][pc_nm] << '\n';
        }
        else if (ch == "-all") {
            for (auto k: data) {
                map<int, vector<string>> output;

                for (auto l: k.second) {
                    output[l.second].push_back (l.first);
                }
        
                for (auto x: output) {
                    sort (x.second.begin(), x.second.end());
                    for (auto m: x.second) {
                        cout << k.first << ' ' << m << ' ' << x.first << '\n';
                    }
                }
            }
        }
    }

    return 0;
}
