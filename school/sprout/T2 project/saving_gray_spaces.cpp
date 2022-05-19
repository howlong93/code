#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <string>
#include <cstring>

#include "bmp_handler.h"

using namespace std;

const int R = 2, G = 1, B = 0;

int main()
{
    // change charset for windows
#ifdef _WIN32
    system("chcp 65001");
#endif

    string filename;

    cerr << "input file: ";
    getline(cin, filename);

    BMP bmp(filename);

    // get image height and width
    int height = bmp.height(), width = bmp.width();

    if (width == 0) {
	    return -1;
    }

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
	{
		int xterm_save = 0;

		xterm_save += bmp.bitmap[i][j][R] + bmp.bitmap[i][j][B] + bmp.bitmap[i][j][G];
		bmp.bitmap[i][j][R] = bmp.bitmap[i][j][B] = bmp.bitmap[i][j][G] = xterm_save/3;
	}
    }

    cerr << "output filename: ";
    getline(cin, filename);

    bmp.save(filename);

    return 0;
}
