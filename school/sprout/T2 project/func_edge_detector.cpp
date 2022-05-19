#include <iostream>
#include <cstdlib>
#include "bmp_handler.h"

using namespace std;

const int R = 2, G = 1, B = 0;

void edge_detect(char* filename)
{
    // change charset for windows
#ifdef _WIN32
    system("chcp 65001");
#endif

    // read in bmp file with filename
    BMP bmp(filename);

    // get image height and width
    int height = bmp.height(), width = bmp.width();

    // Let's draw ascii art!
    int i = 0, j = 0;
    V2d rbg_sum = V2d(height, V1d(width, 0));
   
    for (i = 0; i < height; i++) {
    	for (j = 0; j < width; j++) {
    		int red_num = bmp.bitmap[i][j][R];
    		int blue_num = bmp.bitmap[i][j][B];
    		int green_num = bmp.bitmap[i][j][G];
    		rbg_sum[i][j] = sqrt(double(red_num*red_num + blue_num*blue_num + green_num*green_num)/3);
    		
    	}
    }
    
    int difference = 0;
    for (i = 0; i < height-1; i++) {
    	for (j = 0; j < width-1; j++) {
    		difference = 0;
    		
    		if (i > 0) {
    			difference += rbg_sum[i][j]-rbg_sum[i-1][j];
    		}
    		if (i < height) {
    			difference += rbg_sum[i][j]-rbg_sum[i+1][j];
    		}
    		if (j > 0) {
    			difference += rbg_sum[i][j]-rbg_sum[i][j-1];
    		}
		if (j < width) {
			difference += rbg_sum[i][j]-rbg_sum[i][j+1];
		}

//		cout << "\033[48;5;" << 232 + rbg_sum[i][j]/24;
		if (difference >= 45) {
			cout << "+";
		}
		else {
			cout << " ";
		}
//		cout << "\033[0m";
	}
	cout << endl;
   }
}
