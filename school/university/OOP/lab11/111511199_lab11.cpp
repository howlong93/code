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
        type = name = "";
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
    
    string pc_type, pc_nm;
    int quantity;
    while (input >> pc_type >> pc_nm >> quantity) {
        data[pc_type][pc_nm] += quantity;
    }

    string ch;
    while (cin >> ch) {
        if (ch == "-l") {
            cin >> pc_type >> pc_nm >> quantity;
            data[pc_type][pc_nm] += quantity;
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
            vector<Product> product;
            for (auto k: data) {
                for (auto s : k.second) {
                    Product temp (k.first, s.first, s.second);
                    product.push_back (temp);
                }
            }
            
            sort (product.begin(), product.end(), [] (Product &a, Product &b) {
                    if (a.type != b.type) return a.type < b.type;
                    else if (a.quantity < b.quantity) return a.quantity < b.quantity;
                    else return a.name < b.name;
                });

            for (auto k: product) {
                cout << k.type << ' ' << k.name << ' ' << k.quantity << '\n';
            }
        }
    }

    return 0;
}
