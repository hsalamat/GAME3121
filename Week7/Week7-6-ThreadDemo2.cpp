//In this example, the function can take any number of parameters. 

#include <thread>
#include <string>
#include <iostream>

void func(int i, double d, const std::string& s)
{
    std::cout << i << ", " << d << ", " << s << std::endl;
}

int main()
{
    std::thread t(func, 1, 12.50, "sample");
    t.join();

    return 0;
}
