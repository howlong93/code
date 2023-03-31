#include <assert.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;

void CleanScreen();  //清空螢幕
char get_input();    //自動讀取輸入
void output(int graph[8][8], int vis[8][8], int, int, int, int);  //輸出
int check_position(int graph[8][8], int, int);  //檢查該位置情形
int bomb_around(int graph[8][8], int, int);  //數九宮格內地雷個數

// 不用看懂這個函數
// Clean up the Screen
void CleanScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// 不用看懂這個函數
// function: no need to press enter to input
char get_input() {
    char c = '\0';
    struct termios org_opts, new_opts;
    int res = 0;
    /*---- store old settings ----*/
    res = tcgetattr(STDIN_FILENO, &org_opts);
    assert(res == 0);
    /*---- set new terminal parms ----*/
    memcpy(&new_opts, &org_opts, sizeof(new_opts));
    new_opts.c_lflag &=
        ~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | ECHOPRT | ECHOKE | ICRNL);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_opts);
    c = getchar();
    /*---- restore old settings ----*/
    res = tcsetattr(STDIN_FILENO, TCSANOW, &org_opts);
    assert(res == 0);
    return c;
}

//輸出踩地雷地圖 （每個區塊有 地雷 / 旗標 / 已經點開 三種情形）
void output(int graph[8][8], int vis[8][8], int mined_cnt, int flag_cnt,
            int cursor_row, int cursor_col) {

    cout << "\033[1;32;45m   ";
    for (int i = 0; i < 8; i++) cout << i << ' ';  //輸出直行編號
    cout << "\033[0m\n";

    for (int i = 0; i < 8; i++) {
        cout << "\033[1;32;45m " << i << "\033[0m ";  //輸出橫列編號

        for (int j = 0; j < 8; j++) {
            if (__1__)                      //判斷是否為游標所在區塊
                cout << "\033[5;44m";       //文字閃爍

            if (vis[i][j] == 0) cout << "-" << "\033[0m ";  //未知區塊
            else if (vis[i][j] == 1) {                      //已點開的區塊(可顯示實際值)
                if (__2__) cout << "\033[1;31m" << "*" << "\033[0m ";  //是地雷
                else cout << graph[i][j] << "\033[0m ";                //不是地雷（數字代表周遭九宮格內地雷數
            }
            else if (vis[i][j] == 2) cout << "\033[1;36m" << "$" << "\033[0m "; //旗幟標示

            cout << "\033[0m";  //恢復為cout預設型態
        }
        cout << '\n';
    }

    //輸出目前 點開的區塊數量 / 旗幟標示的數量
    cout << "\033[1;33m\n"
         << "mined places: " << mined_cnt << " /" << 8 * 8 - 10 << '\t'
         << "flagged bombs: " << flag_cnt << " /" << 10 << "\033[0m\n";

    return;
}

//檢查graph[row][col]
int check_position(int graph[8][8], int row, int col) {
    if (__3__)     //不合法的情形
        return 0;  //不做事 >> 直接回傳0

    if (graph[row][col] == -1) return 1;//地雷         >> 回傳1
    if (graph[row][col] == 0) return 2; //周圍都沒地雷 >> 回傳2
    return 3;                           //其他 (自己不是地雷,九宮格內有地雷) >> 回傳3
}

//計算九宮格內有幾顆地雷(自己不是)
int bomb_around(int graph[8][8], int row, int col) {
    int bomb_num = 0;
    for (__4.1__) {
        for (__4.2__) {
            if (i == 0 && j == 0) continue;
            if (__5__) bomb_num++;  //檢查是地雷 >> bomb_num+1
        }
    }
    return bomb_num;
}

int main() {
    /*
     * 變數簡介
     *		graph[][]: 踩地雷地圖
     *		vis[][]:   紀錄區塊造訪/標示情形
     *		mined_cnt: 已經點開的合法區塊數
     *		flag_cnt:  旗幟標示的區塊數
     *		cursor_row:游標所在列
     *		cursor_col:游標所在行
     */

    int graph[8][8] = {0}, vis[8][8] = {0};
    int mined_cnt = 0, flag_cnt = 0;
    int cursor_row = 0, cursor_col = 0;

    //建立踩地雷地圖
    srand(time(NULL));

    //填入地雷
    for (int i = 0; i < 10; i++) {
        int pos = ___6___;
        while (graph[pos / 8][pos % 8] == -1) pos = ___6___;

        graph[pos / 8][pos % 8] = -1;
    }

    //計算每個區塊的數字
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (graph[i][j] == 0) graph[i][j] = ___7___;
        }
    }
    //踩地雷建圖完成

    CleanScreen();
    output(graph, vis, mined_cnt, flag_cnt, cursor_row, cursor_col);

    //開始踩地雷
    bool fail = false;
    while (__8__) {  //當 點開區塊數 = 總區塊數-地雷數 >> 成功
        char ch = '\0';

        CleanScreen();
        output(graph, vis, mined_cnt, flag_cnt, cursor_row, cursor_col);
        while (ch == '\0') ch = get_input();

        if ((ch == 'w' || ch == 65) && check_position(graph, cursor_row - 1, cursor_col)) __9.1__;       // 上
        else if ((ch == 's' || ch == 66) && check_position(graph, cursor_row + 1, cursor_col)) __9.2__;  // 下
        else if ((ch == 'a' || ch == 68) && check_position(graph, cursor_row, cursor_col - 1)) __9.3__;  // 左
        else if ((ch == 'd' || ch == 67) && check_position(graph, cursor_row, cursor_col + 1)) __9.4__;  // 右
        else if (ch == 'j') {   //點開區塊
            if (vis[cursor_row][cursor_col])
                continue;   //已經點開/ 標示旗幟之區塊
            else if (graph[cursor_row][cursor_col] == -1) {         //踩到地雷
                for (int t = 0; t < 8 * 8; t++) vis[t/8][t%8] = 1;  //標記整張圖都被點開
                fail = true;                                        //標記已經踩到地雷
            }
            else if (graph[cursor_row][cursor_col] > 0) {   //周圍九宮格內有地雷 >> 只挖開一格
                vis[cursor_row][cursor_col] = 1;
                ___9___;                                    //更新挖開區塊數
            }
            else { //點開區塊周圍九宮格沒有地雷
                // BFS （不用懂這裡）

                queue<int> save;
                save.push(cursor_row * 8 + cursor_col);

                while (save.size()) {
                    int cur = save.front();
                    int cur_row = cur / 8, cur_col = cur % 8;
                    save.pop();

                    if (vis[cur_row][cur_col]) continue;

                    cursor_row = cur_row;
                    cursor_col = cur_col;
                    vis[cur_row][cur_col] = 1;
                    mined_cnt++;

                    if (check_position(graph, cur_row, cur_col) == 2) {
                        for (int i = -1; i <= 1; i++) {
                            for (int j = -1; j <= 1; j++) {
                                if (i == 0 && j == 0) continue;
                                if (check_position(graph, cur_row+i, cur_col+j) > 1 && !vis[cur_row+i][cur_col+j])
                                    save.push((cur_row+i) * 8 + (cur_col + j));
                            }
                        }
                    }
                }

                // end BFS
            }
        }
        else if (ch == 'k') {                       //標示旗幟
            if (vis[cursor_row][cursor_col] == 0) { //原本沒被標示旗幟
                vis[cursor_row][cursor_col] = 2, flag_cnt++;
            }
            else if (vis[cursor_row][cursor_col] == 2) {  //原本有標示旗幟
                vis[cursor_row][cursor_col] = 0, flag_cnt--;
            }
        }

        CleanScreen();
        output(graph, vis, mined_cnt, flag_cnt, cursor_row, cursor_col);

        if (fail) {  //踩到地雷
            cout << "\033[1;5;31m\n\t\t"
                 << "Stepped on bomb!!"
                 << "\033[0m\n";
            break;
        }
    }

    //成功結束 >> 輸出 "\\\ You Win ! ///"
    if (!fail) cout << "\033[1;5;32m\n\t\t" << ____11____ << "\033[0m\n";

    return 0;
}
