#include <iostream>

using namespace std;

int main() {
    int score;
    char grade[11] = {'E', 'E', 'E', 'E', 'E', 'E', 'D', 'C', 'B', 'A', 'A'};
    cin >> score;

    cout << grade[score / 10];

    return 0;
}
