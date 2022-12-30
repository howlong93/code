#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;

#define SIZE 4
#define BOMB_NUM 5

void CleanScreen();
void output (int graph[SIZE][SIZE], int vis[SIZE][SIZE], int, int);
int check (int graph[SIZE][SIZE], int, int);
int bomb_in_area (int graph[SIZE][SIZE], int, int);

void CleanScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void output (int graph[SIZE][SIZE], int vis[SIZE][SIZE], int mined_cnt, int flag_cnt) {
	cout << "\033[1;32;45m   ";
	for (int i = 0; i < SIZE; i++) cout << i << ' ';
	cout << "\033[0m\n";

	for (int i = 0; i < SIZE; i++) {
		cout << "\033[1;32;45m " << i << "\033[0m ";
		for (int j = 0; j < SIZE; j++) {
			if (vis[i][j] == 0) cout << "- ";
			else if (vis[i][j] == 1) {
				if (graph[i][j] == -1) cout << "\033[1;31m*\033[0m ";
				else cout << graph[i][j] << ' ';
			}
			else if (vis[i][j] == 2) cout << "\033[1;33m!\033[0m ";
		}
		cout << '\n';
	}

	cout << "\033[1;33m\n"
         << "mined places: " << mined_cnt << " /" << SIZE*SIZE << '\t'
         << "flagged bombs: " << flag_cnt << " /" << BOMB_NUM
	     << "\033[0m\n";

	return;
}

int check (int graph[SIZE][SIZE], int row, int col) {
	if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) return 0;
	if (graph[row][col] == -1) return 1;
	if (graph[row][col] == 0) return 2;
	else return 3;
}

int bomb_in_area (int graph[SIZE][SIZE], int row, int col) {
	int bomb_num = 0;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (i == 0 && j == 0) continue;
			if (check (graph, row+i, col+j) == 1)
				bomb_num++;
		}
	}
	return bomb_num;
}

int main() {
	srand(time(NULL));

	//build graph
	int graph[SIZE][SIZE] = {0}, vis[SIZE][SIZE] = {0}, mined_cnt = 0, flag_cnt = 0;

	for (int i = 0; i < BOMB_NUM; i++) {
		int pos = (int) ((double) rand()/RAND_MAX * SIZE*SIZE);
		while (graph[pos/SIZE][pos%SIZE] == -1) 
			pos = (int) ((double) rand()/RAND_MAX * SIZE*SIZE);
		
		graph[pos/SIZE][pos%SIZE] = -1;
	}

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (graph[i][j] == 0)
				graph[i][j] = bomb_in_area (graph, i, j);
		}
	}

	CleanScreen();
	output(graph, vis, mined_cnt, flag_cnt);

	bool fail = false;
	while (mined_cnt < SIZE*SIZE - BOMB_NUM) {
		bool on_visited = false;
		int ch, row, col;
		cin >> ch >> row >> col;

		CleanScreen();
		if (check (graph, row, col) == 0) {
			output (graph, vis, mined_cnt, flag_cnt);
			cout << "\033[1;31mout of range!!\033[0m\n";
			continue;
		}

		if (ch == 0) {
			if (vis[row][col])on_visited = true; 
			else if (graph[row][col] == -1) { //stepped on bomb
				for (int t = 0; t < SIZE*SIZE; t++) vis[t/SIZE][t%SIZE] = 1;
				fail = true;
			}
			else if (graph[row][col] > 0) {
				vis[row][col] = 1;
				mined_cnt++;
			}
			else {
				queue<int> save;
				save.push (row*SIZE + col);

				while (save.size()) {
					int cur = save.front();
					int cur_row = cur/SIZE, cur_col = cur%SIZE;
					save.pop();

					if (vis[cur_row][cur_col]) continue;

					vis[cur_row][cur_col] = 1;
					mined_cnt++;
	
					if (check (graph, cur_row, cur_col) == 2) {
						for (int i = -1; i <= 1; i++) {
							for (int j = -1; j <= 1; j++) {
								if (i == 0 && j == 0) continue;
								if (check (graph, cur_row+i, cur_col+j) > 1 && !vis[cur_row+i][cur_col+j])
									save.push ((cur_row+i) * SIZE + (cur_col+j));
							}
						}
					}
				}
			}
		}
		else if (ch == 1) {
			if (vis[row][col] == 1) on_visited = true;
			else if (vis[row][col] == 0) vis[row][col] = 2, flag_cnt++;
			else if (vis[row][col] == 2) vis[row][col] = 0, flag_cnt--;
		}

		output (graph, vis, mined_cnt, flag_cnt);

		//special cases : visited, lose
		if (on_visited) cout << "\033[1;33mVertex visited!!\033[0m\n";
		if (fail) {
			cout << "\033[1;5;31mStepped on bomb\033[0m\n";
			break;
		}
	}

	if (!fail) cout << "\033[5;32mYou win!!!\033[0m\n";

	return 0;
}
