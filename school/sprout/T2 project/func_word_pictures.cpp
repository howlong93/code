#include <iostream>
#include <cstdlib>
#include "bmp_handler.h"

using namespace std;

const int R = 2, G = 1, B = 0;

void word_picture(char* filename)
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
        	int rbg_sum = (bmp.bitmap[i][j][R]+bmp.bitmap[i][j][B]+bmp.bitmap[i][j][G])/3;
        	
        	if (rbg_sum >= 200) {
        		cout << " ";
        	}
        	else if (rbg_sum >= 150) {
        		cout << "'";
        	}
        	else if (rbg_sum >= 100) {
        		cout << "~";
        	}
        	else if (rbg_sum >= 50) {
        		cout << "+";
        	}
        	else if (rbg_sum >= 0) {
        		cout << "#";
        	}
        	
        }
        cout << endl;
    }

}
