//In this example, t is a thread object representing the thread under which function func() runs. 
//The call to join blocks the calling thread (in this case, the main thread) until the joined thread finishes execution. 
//If the thread function returns a value, it is ignored. 

#include <thread>

//step1
void func()
{
	// do some work
}

int main()
{
	std::thread t(func);
	t.join();

	return 0;
}

