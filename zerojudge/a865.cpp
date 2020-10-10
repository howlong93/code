#include <iostream>

using namespace std;

int main() {
    string input;
    cin >> input;
    while (input != ".") {
        int cnt = 0;
        for (auto k : input) {
            switch (k) {
                case 'A':
                    cnt += 1;
                    break;
                case 'B':
                    cnt += 2;
                    break;
                case 'G':
                    cnt += 3;
                    break;
                case 'D':
                    cnt += 3;
                    break;
                case 'E':
                    cnt += 5;
                    break;
                case '#':
                    cnt += 6;
                    break;
                case 'Z':
                    cnt += 7;
                    break;
                case 'Y':
                    cnt += 8;
                    break;
                case 'H':
                    cnt += 9;
                    break;
                case 'I':
                    cnt += 10;
                    break;
                case 'K':
                    cnt += 20;
                    break;
                case 'L':
                    cnt += 30;
                    break;
                case 'M':
                    cnt += 40;
                    break;
                case 'N':
                    cnt += 50;
                    break;
                case 'X':
                    cnt += 60;
                    break;
                case 'O':
                    cnt += 70;
                    break;
                case 'P':
                    cnt += 80;
                    break;
                case 'Q':
                    cnt += 90;
                    break;
                case 'R':
                    cnt += 100;
                    break;
                case 'S':
                    cnt += 200;
                    break;
                case 'T':
                    cnt += 300;
                    break;
                case 'U':
                    cnt += 400;
                    break;
                case 'F':
                    cnt += 500;
                    break;
                case 'C':
                    cnt += 600;
                    break;
                case '$':
                    cnt += 700;
                    break;
                case 'W':
                    cnt += 800;
                    break;
                case '3':
                    cnt += 900;
                    break;
            }
        }
        cout << cnt << "\n";
        cin >> input;
    }

    return 0;
}
