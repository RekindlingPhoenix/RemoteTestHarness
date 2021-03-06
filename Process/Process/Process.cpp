///////////////////////////////////////////////////////////////////////
// Process.cpp - class used to start process                         //
// ver 1.0                                                           //
// Jim Fawcett, CSE687 - Object Oriented Design, Spring 2018         //
///////////////////////////////////////////////////////////////////////

#include "Process.h"
#include <iostream>
#include<time.h>
#include<windows.h>
#include<vector>
#ifdef TEST_PROCESS

int num = 10;
bool flag = true;
std::vector<std::string>inuse;
void ReCreateProcess(int &k)
{
	Process p;
	p.title("test application");
	std::string appPath = "../Debug/this.exe";
	p.application(appPath);

	std::string cmdLine =std::to_string(k);
	p.commandLine(cmdLine);
	
	std::cout << "\n  starting process: \"" << appPath << "\"";
	std::cout << "\n  with this cmdlne: \"" << cmdLine << "\"";
	inuse.push_back(cmdLine);
	
	p.create();
	if (flag) {
		CBP callback = [&]() {  k += 10; ReCreateProcess(k); };
		p.setCallBackProcessing(callback);
		p.registerCallback();
	}

	std::cout << "\n  after OnExit\n";
	
	for (std::string i : inuse)
	{
		std::cout << i
			<< " ";
	}
	std::cout << "\n";
	
	std::cout.flush();
}
int main()
{
	
	std::cout << "\n  Demonstrating code pop-up in notepad";
	std::cout << "\n ======================================";
	
	for (int i = 0; i < 4; ++i)
	{

		Process p;
		p.title("test application");
		std::string appPath = "../Debug/this.exe";
		p.application(appPath);

		std::string cmdLine = std::to_string(i);
		p.commandLine(cmdLine);

		std::cout << "\n  starting process: \"" << appPath << "\"";
		std::cout << "\n  with this cmdlne: \"" << cmdLine << "\"";
		inuse.push_back(cmdLine);
		p.create();
	
		if (flag) {
			CBP callback = [&]() { ReCreateProcess(i); };
			p.setCallBackProcessing(callback);
			p.registerCallback();
		}
	
		std::cout << "\n  after OnExit\n";
		
		for (std::string i : inuse)
		{
			std::cout << i
				<< " ";
		}
		std::cout << "\n";

		
		std::cout.flush();
	}
	getchar();
	return 0;
}

#endif
