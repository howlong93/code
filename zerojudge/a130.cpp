#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct type {
    string name;
    int rela;
};

int main() {
    int i = 0, amount = 0;
    cin >> amount;

    for (i = 1; i <= amount; i++) {
        cout << "Case #" << i << ":\n";
        int keep;
        string name;
        vector<int> answer;
        type data[10];
        for (int j = 0; j < 10; j++) {
            cin >> name >> keep;
            data[j].name = name;
            data[j].rela = keep;

            if (answer.empty() || data[j].rela > data[answer[0]].rela) {
                answer.clear();
                answer.emplace_back(j);
            } else if (data[j].rela == data[answer[0]].rela)
                answer.emplace_back(j);
        }

        for (auto k : answer) cout << data[k].name << "\n";
    }

    return 0;
}
