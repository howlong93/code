#include <iostream>
#include <fstream>
#include <string>

#include "help.h"
#include "ebook.h"

using namespace std;

int *find_position(const char text[], const char pattern[])
{
    static int index[MAX_LEN];
    bool equal_flag;
    int dir = 0, words = 0, i = 0;
    for (dir = 0; dir <= strlen(text)-strlen(pattern); dir++) {
    	equal_flag = true;
       	for (words = 0; words < strlen(pattern); words++) {
    		if(text[dir+words] != pattern[words]) {
    			equal_flag = false;
    			break;
    		}
    	}
    	
       	if (equal_flag == true) {
    		index[i] = dir;
    		i++;
    	}
    }
    index[i] = -1;
    /* Find all the matching pattern in text and put their indices in the array*/
    return index;
}

//function with commands
int RunCmd(EBook &book, int &pid, const char cmd[])
{
	static int keep_page = 0;
	static vector<int> prev_page;
    // command: Search
    if (strcmp(cmd, "Search") == 0) {
        FindString(book, pid);
        return true;
    }
    
	// command: exit
    else if (strcmp(cmd, "exit") == 0) {
    	
    	int total_score = 0, full_score = 0;
    	
    	CleanScreen();
    	
    	std::cout << "your score is: ";
    	
    	for (pid = 0; pid < book.MaxResourceId; pid++) {
    		if (book.page[pid].if_correct == true) {
    			total_score += 10;
    		}
    		if (book.page[pid].question != "" || book.page[pid].answer != "") {
    			full_score += 10;
    		}
    	}
    	
    	std::cout << total_score << " /" << full_score << std::endl;
    	std::string output = "book closed!!\n";
    	
    	for (int j = 0; j < output.size(); j++) {
    		std::cout << output[j];
    		Sleep(50);
    	}
    	
    	std::ifstream fout("review.txt");
    //	Sleep(1000); 
    	return 2;
    }
    
	// command: goto
    else if (strncmp(cmd, "goto", 4) == 0) {
    	//goto page...
    	prev_page.push_back(pid);
		int following_page = 0;
    	following_page = cmd[5]-'0';
		for (int i = 6; cmd[i] != '\0'; i++) {
			following_page = following_page*10+cmd[i]-'0';
		}
		
		if (following_page < MAX_PAGE) {
			pid = following_page;
    		PrintPage(book, pid);
    	}
    	else {
    		cout << "Last page!!";
    		Sleep(2000);
    		CleanScreen();
    		PrintPage(book, pid, false);
    	}
    	
    	return true;
    }
    
    // command: Turn to Page
    else if (strcmp(cmd, "Turn to Page num") == 0) {
    	int turn_page = 0;
    	cout << "get to page: ";
    	cin >> turn_page;
    	if (turn_page >= 0 && turn_page < MAX_PAGE) {
    		prev_page.push_back(pid);
    		pid = turn_page;
    		PrintPage(book, pid);
    	}
    	else {
    		cout << "range between " << 0 << " ~ " << MAX_PAGE-1;
    		Sleep(1000);
    		PrintPage(book, pid, false);
    	}
    	
    	return true;
    }
    	
	// command: Qsave
    else if (strcmp(cmd, "Qsave") == 0) {
 		keep_page = pid;   	
    	return true;
    }
    
	// command: Qload
    else if (strcmp(cmd, "Qload") == 0) {
    	prev_page.push_back(pid);
    	pid = keep_page;
    	PrintPage(book, pid);
    	return true;
    }
    
	// command: Reload Page
    else if (strcmp(cmd, "Reload Page") == 0) {
    	CleanScreen();
    	PrintPage(book, pid, false);
    	return true;
    }
    
    // command: Previous Page
    else if (strcmp(cmd, "Previous Page") == 0) {
    	if (prev_page.end() == prev_page.begin()) {
    		cout << "no previous page";
    		Sleep(1000);
    		CleanScreen();
    		PrintPage(book, pid, false);
    	}
    	else {
    		pid = *(prev_page.end()-1);
    		prev_page.pop_back();    		
    		PrintPage(book, pid);
    	}
    	return true;
    }
    
    //command: Take Test
    else if (strcmp(cmd, "Take Test") == 0) {
    	if (book.page[pid].question == "" && book.page[pid].answer == "") {
    		string output = "no question!!";
    		CleanScreen();
    		for (int i = 0; i < output.size(); i++) {
    			cout << output[i];
    			Sleep(50);
    		}
    		Sleep(500);
    		CleanScreen();
    		PrintPage(book, pid, false);
    	}
    	else {
	    	string response;
	    	CleanScreen();
	    	std::cout << book.page[pid].test_image;
	    	std::cout << std::string(100, '=') << endl; 
	    	
	    	for (int i = 0; i < book.page[pid].question.size(); i++) {
	    		cout << book.page[pid].question[i];
	    		Sleep(50);
	    	}
	    	
	    	std::getline(cin, response);
	    	while (response != book.page[pid].answer) {
	    		cout << "Wrong answer";
	    		if (book.page[pid].if_correct == true) {
	    			book.page[pid].if_correct = false;
	    		}
	    		Sleep(1000);
	    		CleanScreen();
	    		std::cout << book.page[pid].test_image;
	    		cout << string(100, '=') << endl;
	    		cout << book.page[pid].question << "\n[press 'l' to leave]\n";
	    		getline(cin, response);
	    		if (response == "l") {
	    			PrintPage(book, pid, false);
	    			break;
	    		}
	    	}
	    	
	    	if (response == book.page[pid].answer) {
	    		cout << "Correct";
	    		Sleep(1000);
	    		book.page[pid].if_correct = true;
	    		PrintPage(book, pid, false);
	    	}
    	}
    	return true;
    }
    	 		
    
    /* TODO: handle other commands*/
    /* else if... */
    return false;
}

int main()
{
    EBook book;
    const char *bookname = "review.txt";
    if (!LoadBook(bookname, book)) {
        return -1;
    }
    
    std::cout << "load book " << bookname << "!" << std::endl;
    std::cout << "Press any key to read the book" << std::endl;
    Getch();

    int current = 0;
    PrintPage(book, current);
    while (true)
    {
    	int flag = GetCmd(book, current);
        if (!flag)
        {
            std::cerr << "Something went wrong..." << std::endl;
            break;
        }
        else if (flag == 2) {
        	break;
        }
    }

    return 0;
}
