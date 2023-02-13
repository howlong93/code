#include <iostream>
#include <cstdlib>
#include <queue>
#include <unistd.h>
#include <assert.h>
#include <termios.h>
#include <string.h>

using namespace std;

#define SIZE 8
#define BOMB_NUM 10

void CleanScreen();	//清空螢幕
char get_input();   //自動讀取輸入
void output (int graph[SIZE][SIZE], int vis[SIZE][SIZE], int, int, int, int);  //輸出
int check_position_status (int graph[SIZE][SIZE], int, int);  //檢查該位置情形
int bomb_around (int graph[SIZE][SIZE], int, int);            //數九宮格內炸彈個數

// Do not need to understand this function
// Clean up the Screen
void CleanScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Do not need to understand this function
// function: no need to press enter to input
char get_input(void) {
    char c = '\0';
    struct termios org_opts, new_opts;
    int res = 0;
    /*---- store old settings ----*/
    res = tcgetattr(STDIN_FILENO, &org_opts);
    assert(res == 0);
    /*---- set new terminal parms ----*/
    memcpy(&new_opts, &org_opts, sizeof(new_opts));
    new_opts.c_lflag &= ~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | ECHOPRT | ECHOKE | ICRNL);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_opts);
    c = getchar();
    /*---- restore old settings ----*/
    res = tcsetattr(STDIN_FILENO, TCSANOW, &org_opts);
    assert(res == 0);
    return c;
}

//輸出
//output mine graph (unknown / flagged / revealed)
void output (int graph[SIZE][SIZE], int vis[SIZE][SIZE], int mined_cnt, int flag_cnt,
			 int cursor_row, int cursor_col) {

	//輸出直行編號
	cout << "\033[1;32;45m   ";
	for (int i = 0; i < SIZE; i++) cout << i << ' ';
	cout << "\033[0m\n";

	for (int i = 0; i < SIZE; i++) {
		//輸出橫列編號
		cout << "\033[1;32;45m " << i << "\033[0m ";

		for (int j = 0; j < SIZE; j++) {
			if (i == cursor_row && j == cursor_col)	//判斷是否為游標所在地塊
				cout << "\033[5;44m";				//文字閃爍

			if (vis[i][j] == 0) cout << "-" << "\033[0m ";	//未知地塊
			else if (vis[i][j] == 1) {						//已點開的地塊(可顯示實際值)
				if (graph[i][j] == -1) cout << "\033[1;31m" << "*" << "\033[0m "; //炸彈
				else cout << graph[i][j] << "\033[0m ";							  //非炸彈（數字代表周遭九宮格內炸彈數
			}
			else if (vis[i][j] == 2) cout << "\033[1;36m" << "$" << "\033[0m ";   //旗標標示

			cout << "\033[0m"; //恢復為cout預設型態
		}
		cout << '\n';
	}

	//輸出目前 已知的地塊數量 / 旗幟標示的數量
	cout << "\033[1;33m\n"
         << "mined places: " << mined_cnt << " /" << SIZE*SIZE - BOMB_NUM << '\t'
         << "flagged bombs: " << flag_cnt << " /" << BOMB_NUM
	     << "\033[0m\n";

	return;
}

//檢查graph[row][col]
int check_position_status (int graph[SIZE][SIZE], int row, int col) {
	if (row < 0 || row >= SIZE || col < 0 || col >= SIZE)
		return 0;                           //不合法 ([row][col]標示的位置在範圍外) >> 回傳0

	if (graph[row][col] == -1) return 1;	//炸彈         >> 回傳1
	if (graph[row][col] == 0) return 2;     //周圍都沒炸彈 >> 回傳2
	return 3;                               //其他 (自己不是炸彈,九宮格內有炸彈) >> 回傳3
}

//計算九宮格內有幾顆炸彈(自己不是)
int bomb_around (int graph[SIZE][SIZE], int row, int col) {
	int bomb_num = 0;
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (i == 0 && j == 0) continue;
			if (check_position_status (graph, row+i, col+j) == 1) //如果檢查是炸彈 >> bomb_num+1
				bomb_num++;
		}
	}
	return bomb_num;
}

int main() {

	/*
	 * 變數簡介
	 *		graph[][]: 踩地雷地圖
	 *		vis[][]:   紀錄地塊造訪/標示情形
	 *		mined_cnt: 已經點開的合法地塊數
	 *		flag_cnt:  旗幟標示的地塊數
	 *		cursor_row:游標所在列
	 *		cursor_col:游標所在行
	 */

	int graph[SIZE][SIZE] = {0}, vis[SIZE][SIZE] = {0};
	int mined_cnt = 0, flag_cnt = 0;
	int cursor_row = 0, cursor_col = 0;

	//建立踩地雷地圖
	srand(time(NULL));
	
	//填入炸彈
	for (int i = 0; i < BOMB_NUM; i++) {
		int pos = (int) ((double) rand()/RAND_MAX * SIZE*SIZE);
		while (graph[pos/SIZE][pos%SIZE] == -1) 
			pos = (int) ((double) rand()/RAND_MAX * SIZE*SIZE);
		
		graph[pos/SIZE][pos%SIZE] = -1;
	}

	//計算每個地塊要顯示的數字
	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			if (graph[i][j] == 0)
				graph[i][j] = bomb_around (graph, i, j);
		}
	}
	//踩地雷建圖完成

	CleanScreen();
	output(graph, vis, mined_cnt, flag_cnt, cursor_row, cursor_col);

	//開始踩地雷
	bool fail = false;
	while (mined_cnt < SIZE*SIZE - BOMB_NUM) {	//當 點開地塊數 = 總地塊數-炸彈數 >> 勝
		char ch = '\0';

		CleanScreen();
		output(graph, vis, mined_cnt, flag_cnt, cursor_row, cursor_col);
		while (ch == '\0') ch = get_input();

		if ((ch == 'w' || ch == 65) && check_position_status (graph, cursor_row-1, cursor_col)) cursor_row--;       // 上
		else if ((ch == 's' || ch == 66) && check_position_status (graph, cursor_row+1, cursor_col)) cursor_row++;  // 下
		else if ((ch == 'a' || ch == 68) && check_position_status (graph, cursor_row, cursor_col-1)) cursor_col--;  // 左
		else if ((ch == 'd' || ch == 67) && check_position_status (graph, cursor_row, cursor_col+1)) cursor_col++;  // 右
		else if (ch == '0') { //點開地塊
			if (vis[cursor_row][cursor_col] == 1) continue; //已點開之地塊
			else if (graph[cursor_row][cursor_col] == -1) { //踩到炸彈
				for (int t = 0; t < SIZE*SIZE; t++) vis[t/SIZE][t%SIZE] = 1; //顯示整張圖
				fail = true;  //標記已失敗
			}
			else if (graph[cursor_row][cursor_col] > 0) {  //周圍九宮格內有炸彈
				vis[cursor_row][cursor_col] = 1;
				mined_cnt++;
			}
			else {	    //點開之地塊周遭九宮格沒有炸彈
				//BFS
				queue<int> save;
				save.push (cursor_row*SIZE + cursor_col);

				while (save.size()) {
					int cur = save.front();
					int cur_row = cur/SIZE, cur_col = cur%SIZE;
					save.pop();

					if (vis[cur_row][cur_col]) continue;

					cursor_row = cur_row;
					cursor_col = cur_col;
					vis[cur_row][cur_col] = 1;
					mined_cnt++;
	
					if (check_position_status (graph, cur_row, cur_col) == 2) {
						for (int i = -1; i <= 1; i++) {
							for (int j = -1; j <= 1; j++) {
								if (i == 0 && j == 0) continue;
								if (check_position_status (graph, cur_row+i, cur_col+j) > 1 && !vis[cur_row+i][cur_col+j])
									save.push ((cur_row+i) * SIZE + (cur_col+j));
							}
						}
					}
				}
			}
		}
		else if (ch == '1') { //標示旗幟
			if (vis[cursor_row][cursor_col] == 0) //原本沒被標示旗幟
				vis[cursor_row][cursor_col] = 2, flag_cnt++;
			else if (vis[cursor_row][cursor_col] == 2) //已經有標示旗幟
				vis[cursor_row][cursor_col] = 0, flag_cnt--;
		}

		CleanScreen();
		output (graph, vis, mined_cnt, flag_cnt, cursor_row, cursor_col);

		//lose
		if (fail) {
			cout << "\033[1;5;31mStepped on bomb!!\033[0m\n";
			break;
		}
	}

	if (!fail) cout << "\033[1;5;32mYou win!!!\033[0m\n";

	return 0;
}
