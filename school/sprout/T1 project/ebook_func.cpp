#include <string>
#include <iostream>
#include <fstream>

#include "ebook.h"
void CleanScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
int text_line = 0, cmd_line = 0;
void CleanText(Page &page)
{
    for (int i = 0; i < cmd_line + text_line; ++i)
    {
        std::cout << PLINE;
        for (int i = 0; i < 100; ++i)
            std::cout << '\b';
        for (int i = 0; i < 100; ++i)
            std::cout << ' ';
        for (int i = 0; i < 100; ++i)
            std::cout << '\b';
    }
    text_line = cmd_line = 0;
}

void CleanCmd(Page &page)
{
    for (int i = 0; i < cmd_line; ++i)
    {
        std::cout << PLINE;
        for (int i = 0; i < 100; ++i)
            std::cout << '\b';
        for (int i = 0; i < 100; ++i)
            std::cout << ' ';
        for (int i = 0; i < 100; ++i)
            std::cout << '\b';
    }
    cmd_line = 0;
}

void PrintCmd(Page &page)
{
    cmd_line = 1;
    std::cout << "Please enter command: " << std::endl;
    for (int i = 0; i < 256; ++i)
    {
        if (page.cmd[i] != "")
        {
        	if (page.cmd[i] == "Take Test") {
        		if (page.question != "") {
        			std::cout << "[" << char(i) << "]: " << page.cmd[i] << std::endl;
        		}
        	}
        	else {
            	std::cout << "[" << char(i) << "]: " << page.cmd[i] << std::endl;
            	++cmd_line;
            }
        }
    }
}

void PrintText(Page &page, int pid, bool animation, int *indices, int p_len)
{
    int len = strlen(page.text), cur = 0;
    text_line = 0;
    for (int i = 0, char_count = 0; i < len; ++i)
    {
        if (animation)
            SleepMs(35);
        if (page.text[i] == '\n' || (page.text[i] == ' ' && char_count >= 60))
        {
            std::cout << std::endl;
            ++text_line;
            char_count = 0;
        }
        else
        {
            if (p_len && i == indices[cur])
                std::cout << GREEN;
            std::cout << page.text[i] << std::flush;
            if (p_len && i == indices[cur] + p_len - 1)
            {
                std::cout << RESET;
                ++cur;
            }
            ++char_count;
        }
    }
    std::cout << std::string(100, '=') << std::endl;
    std::cout << "page " << pid << ".\n"
              << std::endl;
    text_line += 3;
    PrintCmd(page);
}

void PrintPage(EBook &book, int pid, bool animation)
{
    CleanScreen();
    std::cout << book.page[pid].image << std::endl;
    std::cout << std::string(100, '=') << std::endl;
    PrintText(book.page[pid], pid, animation);
}

void FindString(EBook &book, int& pid) 
{
    CleanCmd(book.page[pid]);
    std::cout << "Please enter the string to look for: " << std::flush;
    ++cmd_line;
    std::string pattern;
    std::cin >> pattern;
    int *indices = find_position(book.page[pid].text, pattern.c_str());
    
	if (indices[0] == -1) {
    	std::string words = "No such pattern!!";
      	for (int i = 0; i < words.size(); i++) {
    		std::cout << words[i];
    		Sleep(50);
    	}
    	CleanText(book.page[pid]);
    	PrintText(book.page[pid], pid, false, indices, pattern.length());
    }
    else {
    	CleanText(book.page[pid]);
    	PrintText(book.page[pid], pid, false, indices, pattern.length());
    }
}

int GetCmd(EBook &book, int &pid)
{
    while (int c = Getch())
    {
        if (book.page[pid].cmd[c] != "")
        {
        	return RunCmd(book, pid, book.page[pid].cmd[c].c_str());
        }
    }
    return -1;
}
