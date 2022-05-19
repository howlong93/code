#include <iostream>
#include <cstdlib>
#include <unistd.h>

#include "bmp_handler.h"

using namespace std;

const int R = 2, G = 1, B = 0;

int main()
{
    // change charset for windows
#ifdef _WIN32
    system("chcp 65001");
#endif

    // read in bmp file with filename
    string filename;

    cerr << "input filename: ";
    getline(cin, filename);

    BMP bmp(filename);
   // get image height and width
    int height = bmp.height(), width = bmp.width();

    if (width == 0) {
	    return -1;
    }

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++)
	{
		for (int l = 0; l < 3; l++) {
			bmp.bitmap[i][j][l] = 255-bmp.bitmap[i][j][l];
		}
	}
    }
    if (bmp.height() != 0) {
	    cerr << "output filename: ";
	    getline(cin, filename);
	    bmp.save(filename);
    }

    return 0;
}

