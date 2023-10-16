//Even though it's possible to pass any number of parameters to the thread function, all parameters are passed by value. 
// If the function needs to take parameters by reference, the passed arguments must be wrapped in a std::ref or std::cref like in the following example.
//The program prints 43, but without wrapping a in a std::ref, the output would be 42.

#include <thread>
#include <string>
#include <iostream>

void func(int& a)
{
	a++;
}

int main()
{
	int a = 42;
	std::thread t(func, std::ref(a));
	t.join();

	std::cout << a << std::endl;

	return 0;
}
