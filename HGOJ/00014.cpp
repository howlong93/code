#include <iostream>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {
    int amount = 0, i = 0;
    stack<int> numbers;
    stack<string> calc, input;
    string keep;

    cin >> amount;
    cin.clear();

    for (i = 0; i < amount; i++) {
        cin >> keep;
        input.push(keep);
    }

    keep = "";
    while (input.size()) {
        keep = input.top();
        input.pop();
        if (keep == "+" || keep == "-" || keep == "*" || keep == "/" ||
            keep == "%") {
            int a, b;

            a = numbers.top();
            numbers.pop();
            b = numbers.top();
            numbers.pop();

            if (keep == "+")
                numbers.push(a + b);
            else if (keep == "-")
                numbers.push(a - b);
            else if (keep == "*")
                numbers.push(a * b);
            else if (keep == "/")
                numbers.push(a / b);
            else if (keep == "%")
                numbers.push(a % b);
        } else {
            stringstream ss;
            int save = 0;
            ss << keep;
            ss >> save;
            numbers.push(save);
        }
    }

    cout << numbers.top();

    return 0;
}
