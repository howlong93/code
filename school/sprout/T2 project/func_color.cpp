#include <iostream>
#include <cstdlib>

#include "bmp_handler.h"

using namespace std;

const int R = 2, G = 1, B = 0;

int decide_color (int);

void color (char* filename)
{
    // change charset for windows
#ifdef _WIN32
    system("chcp 65001");
#endif

    // read in bmp file with filename "fireworks.bmp"
    BMP bmp(filename);

    // get image height and width
    int height = bmp.height(), width = bmp.width();

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
	{
		int xterm_save = 0;

		xterm_save += 100 * decide_color(bmp.bitmap[i][j][R]);
		xterm_save += 10 * decide_color(bmp.bitmap[i][j][G]);
		xterm_save += decide_color(bmp.bitmap[i][j][B]);

		cout << "\033[48;5;" << xterm_save%10 + 6*( (xterm_save%100)/10) + 36*(xterm_save/100) + 16 << "m ";
		cout << "\033[0m";
	}
	cout << endl;
    }
}

int
decide_color(int x)
{
	int gap[6] = {0}, i = 0, keep = 0;
	int darkness[6] = {0, 95, 135, 175, 215, 255};

	for (i = 0; i < 6; i++) {
		gap[i] = abs(darkness[i]-x);
	}

	for (i = 0; i < 6; i++) {
		if (gap[i] < gap[keep]) {
			keep = i;
		}
	}

	return keep;
}
