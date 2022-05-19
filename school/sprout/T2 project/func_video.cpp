#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <sstream>
#include <cstring>

#include "bmp_handler.h"

#define PIC_AMOUNT 49

using namespace std;

void
video(int way)
{
	int i = 0, keep = 0;
	stringstream ss;

	CleanScreen();
	sleep(1);

	for (i = 1; i <= PIC_AMOUNT; i++) {
		char filename[15] = "video_";
		ss << i;
		for (keep = 0; keep <= (int)log10(i); keep++) {
			ss >> filename[6+keep];
		}

		strcat(filename, ".bmp");

		if (way == 1) {
			word_picture(filename);
		}
		else if (way == 2) {
			edge_detect(filename);
		}
		else if (way == 3) {
			gray_spaces(filename);
		}
		else if (way == 4) {
			color(filename);
		}
		usleep(160000);
		if (i == PIC_AMOUNT) {
			break;
		}
		CleanScreen();
	}
}
