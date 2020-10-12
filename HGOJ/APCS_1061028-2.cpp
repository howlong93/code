#include <iostream>

using namespace std;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    unsigned int length = 0, answer = 0, i = 0, keep = 0, j = 0;
    string input;
    bool flag = false, succeed = false;

    cin >> length;
    cin >> input;

    for (int l = 0; l <= input.size() - length; l++) {
        int cnt = 0;
        i = l;
        keep = 0;
        while (i <= input.size() - length) {
            if (!succeed) {
                if (islower(input[i]))
                    flag = true;
                else
                    flag = false;
            }
            succeed = true;

            for (j = 0; j < length; j++) {
                if (flag && isupper(input[i + j])) {
                    succeed = false;
                    break;
                } else if (!flag && islower(input[i + j])) {
                    succeed = false;
                    break;
                }
            }

            if (succeed) {
                if (flag)
                    flag = false;
                else
                    flag = true;

                i += j;
                keep += j;
                cnt++;
            } else
                break;
        }
        if (cnt > 1) l += (cnt - 2) * length;
        answer = max(answer, keep);
    }

    cout << answer << "\n";

    return 0;
}
