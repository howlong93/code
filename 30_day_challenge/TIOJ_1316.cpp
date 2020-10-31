#include <bits/stdc++.h>

using namespace std;

#define MAX 8005

int num[MAX], l[MAX] = {0}, r[MAX], s[MAX];
bool vis[MAX];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) {
        cin >> s[i];
        if (l[s[i]])
            r[s[i]] = i;
        else
            l[s[i]] = i;
    }

    int cur = 2;
    for (int i = 1; i <= 2 * n; i++) {
        if (i == l[s[i]]) cur--;
        num[i] = cur;
        if (i == r[s[i]]) cur++;
    }

	int ans = n;
    for (int i = 1; i <= 2 * n; i++) {
        while (num[i] < 0) {
            int pos = 0, id;
            for (int j = 1; j <= i; j++) {
                if (!vis[s[j]] && j == l[s[j]] && r[s[j]] > pos) {
                    pos = r[s[j]];
                    id = s[j];
                }
            }
            vis[id] = 1;
            for (int j = l[id]; j <= r[id]; j++) num[j]++;
            ans--;
        }
    }

    cout << ans << '\n';
    return 0;
}
