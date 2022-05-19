#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <cstring>
#include <sstream>
#include <limits>

#include "bmp_handler.h"

#define MAX 8 

using namespace std;

char* select_file (bool *);
int show_picture (char *, bool *);
void finish_progress();

int
main()
{
	CleanScreen();

	string choice;
	bool flag = true;

	while(1) {
	choice = "";
	flag = true;
	CleanScreen();

	cerr << "what do you want to see? [video / photo]\n";
	cin >> choice;
	CleanScreen();

	if (choice == "video") {
		int way = 0, count = 0;

		do {
			if (count > 0) {
				cout << "unable choice\n";
				sleep(1);
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');

				CleanScreen();
			}
			count++;
	                cerr << "choose a way to show the video:\n[1 ~ 4]\n\n1. build with words\n2. edge detect\n3. gray spaces\n4. colored picture\n-1. leave\n\n" << string(75, '=') << "\n\n";
        	} while ( !(cin >> way) );

		CleanScreen();

		if (way == -1) {
			finish_progress();
			break;
		}
		else if (way >= 1 && way <= 4) {
			video(way);
		}
		else {
			flag = false;
			cerr << "unable choice\n";
			sleep(1);
			CleanScreen();
		}
	}
	else if (choice == "photo") {
		char* filename;
		int leave = 0;

		if (flag) {
			filename = select_file(&flag);
		}

		leave = show_picture(filename, &flag);

		if (leave == -1) {
			finish_progress();
			break;
		}
	}
	else {
		flag = false;
		cerr << "unable choice\n";
		sleep(1);
		CleanScreen();
	}

	if (flag) {
		char c;
		c = getchar();

		cerr << "result showed\n[press enter to continue, l to leave] "; 
		if ((c = getchar()) == '\n') {
			;
		}
		else if (c == 'l') {
			finish_progress();
                        break;
		}
	}

	CleanScreen();
	}

	return 0;
}



char *
select_file (bool *flag)
{
	int photo = 0, count = 0;
	char *filename = NULL;

	do {
		if (count > 0) {
			cout << "unable choice\n";
			sleep(1);

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			
			CleanScreen();
		}
		
		count++;
		cerr << "choose a picture you want to see:\n[1 ~ " << MAX << "]\n\n1. airplane\n2. eagle\n3. tiger\n4. evil\n5. baseball\n6. basketball\n7. volleyball\n8. spike\n\n";
		cout << string(75, '=') << "\n\n";

	} while ( !(cin >> photo) );

	if (photo >= 1 && photo <= MAX) {
        	switch (photo) {
                	case 1: filename = (char*)"airplane.bmp";
                        	break;
                        case 2: filename = (char*)"eagle.bmp";
                                break;
                        case 3: filename = (char*)"tiger.bmp";
                                break;
                        case 4: filename = (char*)"evil.bmp";
                                break;
                        case 5: filename = (char*)"baseball.bmp";
                                break;
                        case 6: filename = (char*)"basketball.bmp";
                                break;
                        case 7: filename = (char*)"volleyball.bmp";
                                break;
						case 8: filename = (char*)"spike.bmp";
								break;
                }
	}
    else {
      	cout << "unable choice\n" << endl;
        sleep(1);
        *flag = false;
		CleanScreen();
    }

	return filename;
}

int
show_picture (char *filename, bool *flag)
{
	int way = 0, count = 0;
	if (*flag) {
		CleanScreen();
		do {
			if (count > 0) {
				cout << "unable choice\n";
				sleep(1);
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				CleanScreen();
			}
			count++;

			cerr << "choose a way to show the picture:\n[1 ~ 4]\n\n1. build with words\n2. edge detect\n3. gray spaces\n4, colored picture\n-1. leave\n\n" << string(75, '=') << "\n\n";

		} while ( !(cin >> way) );

		CleanScreen();
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
		else if (way == -1) {
			finish_progress();
			return -1;
		}
		else {
			*flag = false;
		}
	}

	return 0;
}

void
finish_progress()
{
	CleanScreen();
	cout << "\033[1;5;15mleaving...\n";
	sleep(3);
	cout << "\033[0m";
	CleanScreen();
}
