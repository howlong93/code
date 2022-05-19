#include <iostream>
#include <cstdlib>
#include <unistd.h>

#include "bmp_handler.h"

using namespace std;

const int R = 2, G = 1, B = 0;

void gray_spaces(char* filename)
{
    // change charset for windows
#ifdef _WIN32
    system("chcp 65001");
#endif

    // read in bmp file with filename
    BMP bmp(filename);

    //cout << "successly input image : " << filename << endl;

    // get image height and width
    int height = bmp.height(), width = bmp.width();

    for(int i = 0; i < height; i++)
    {
        for(int j = 0; j < width; j++)
	{
		int xterm_save = 0;

		xterm_save += (bmp.bitmap[i][j][R] + bmp.bitmap[i][j][B] + bmp.bitmap[i][j][G])/3;
		cout << "\033[48;5;" << xterm_save/24 + 232<< "m ";
		cout << "\033[0m";
	}
	cout << endl;
    }
}
