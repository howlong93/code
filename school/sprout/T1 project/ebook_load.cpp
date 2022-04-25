#include <string>
#include <iostream>
#include <fstream>

#include "ebook.h"

std::string LoadFileContent(std::string path)
{
    std::ifstream fin(path);
    std::string buf, res;

    while (getline(fin, buf))
        res += buf + "\n";

    return res;
}

#define CHECK(X)                                                                      \
    if (!(X))                                                                         \
    {                                                                                 \
        std::cerr << __FILE__ << ":" << __LINE__ << " Read data error!" << std::endl; \
        return false;                                                                 \
    }

bool LoadPage(std::ifstream &fin, EBook &book, int pid)
{
    std::string buf;
    Page page;

    // Default Command
    bool appendGoto = true;

	page.cmd['b'] = "Previous Page";
    page.cmd['s'] = "Search";
    page.cmd['q'] = "Qsave";
    page.cmd['w'] = "Qload";
    page.cmd['e'] = "exit";
    page.cmd['r'] = "Reload Page";
    page.cmd['t'] = "Take Test";
    page.cmd['f'] = "Turn to Page num";
	   
    while (true)
    {
        CHECK(std::getline(fin, buf));

        if (buf == "")
        {
            // Ignore empty line
            continue;
        }

        std::stringstream ss(buf);
        ss >> buf;

        if (buf == "end")
        {
            break;
        }
        if (buf == "markend")
        {
            appendGoto = false;
        }
        else if (buf == "image") {
            std::string ImgPath;
            ss >> ImgPath;
            page.image = LoadFileContent(("img" DIRSPILTTER) + ImgPath);
        }
        else if (buf == "text-begin")
        {
            int len = 0;
            memset(page.text, 0, sizeof(page.text));
            while (true)
            {
                std::string Text;
                getline(fin, Text);
                if (Text == "text-end")
                    break;
                len += Text.length() + 1;
                if (len >= MAX_LEN - 1)
                {
                    std::cerr << "Too much content... ignored." << std::endl;
                    break;
                }
                strcat(page.text, (Text + "\n").c_str());
            }
        }
        else if (buf == "goto") {
            appendGoto = false;
            std::string c;
            int pid;
            ss >> c >> pid;

            if (c.size() == 1) {
                page.cmd[c[0]] = "goto " + std::to_string(pid);
            }
            else {
            	std::cout << "get in wrong\n";
                std::cerr << "Unknown Key : " << c << std::endl;
            }
        }
        else if (buf == "test") {
        	std::string quest;
        	std::getline(fin, quest);
        	if (quest == "img") {
        	    std::string ImgPath;
        	    std::getline(fin, ImgPath);
            	page.test_image = LoadFileContent(("img" DIRSPILTTER) + ImgPath);
            	std::getline(fin, quest);
            }
            
	        while (quest != "end-question") {
        		page.question += (quest + '\n');
        		std::getline(fin, quest);
        	}
        	std::getline(fin, quest);
        	while (quest == "") {
        		std::getline(fin, quest);
        	}
        	page.answer = quest;
    	}
    	
        else
        {
            std::cerr << "Unknown Command : " << buf << std::endl;
            std::cerr << "-- ignore..." << buf << std::endl;
        }
    }

    if (appendGoto) {
        if (page.cmd['d'].empty() && pid + 1 < book.MaxResourceId)
            page.cmd['d'] = "goto " + std::to_string(pid + 1);
        /*if (page.cmd['a'].empty() && pid - 1 > 0)
            page.cmd['a'] = "goto " + std::to_string(pid - 1);*/
    }
    book.page[pid] = page;
    return true;
}

bool LoadBook(const char *Path, EBook &book) {
    std::ifstream fin(Path);

    if (!fin) {
        std::cerr << "Can not open : " << Path << std::endl;
        return false;
    }

    CHECK(fin >> book.MaxResourceId);
    book.page.resize(book.MaxResourceId);

    int page;
    while (fin >> page)
    {
    	fin.get();
        CHECK(LoadPage(fin, book, page));
    }

    if (!fin.eof())
    {
        std::cerr << "Read data error..." << std::endl;
    }

    return true;
}
#undef CHECK
