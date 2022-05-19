#include <iostream>
#include <cstdlib>

#include "bmp_handler.h"

using namespace std;

void CleanScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
