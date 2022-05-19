/*
    This file Maybe very HARD for beginner.
    You can ignore it.
*/

#include "help.h"

#ifdef _WIN32
/*already in conio.h*/
#else
#include <termios.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>
#include <stdio.h>
int getch(void)
{
    int c = 0;
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
#endif

void SleepMs(int millisecond)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(millisecond));
}

int Getch()
{
    //TODO: support arrow key
    int c = getch();
    if (c == 80 || c == 77) {
    	return 'd';
    }
    else if (c == 72 || c == 75) {
    	return 'b';
    }
    return c;
}
