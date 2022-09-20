//Multithreading demo

// thread example
#include <iostream>       // std::cout
#include <thread>         // std::thread
using namespace std;

//C++ language does not provide a sleep function of its own. However, the operating system’s specific files like unistd.h for Linux and Windows.h for Windows provide this functionality.

#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

void foo()
{
	cout << endl << "we started running foo function in its own thread" << endl;
	Sleep(5000);  //5 seconds
	cout << "foo thread is done" << endl;
	//cout.flush();
	
}

void bar(int x)
{
	cout << endl << "we started running bar function in its own thread" << endl;
	Sleep(10000); //10 seconds
	cout << "bar thread is done" << endl;
	//cout.flush();
}

int main()
{
	std::thread first(foo);     // spawn new thread that calls foo()
	std::thread second(bar, 0);  // spawn new thread that calls bar(0)

	std::cout << "main, foo and bar now execute concurrently...\n"<<endl;

	// synchronize threads:
	first.join();                // pauses until first finishes	
	second.join();               // pauses until second finishes

	std::cout << "foo and bar completed.\n";

	return 0;
}