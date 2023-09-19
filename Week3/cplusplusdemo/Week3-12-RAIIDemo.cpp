/** @file Week3-12-RAIIDemo.cpp
 *  @brief RAII Demo
 *
 *  In computer science, resource contention is a conflict over access to a shared resource such as random access memory,
 *  disk storage, cache memory, internal buses or external network devices. 
 *  Resource contention results when multiple processes attempt to use the same shared resource
 *  In computer programming, a mutual exclusion object(mutex) is a program object that allows multiple program threads
 *  to share the same resource, such as file access,
 *  but not simultaneously.When a program is started, a mutex is created with a unique name
 *
 *  @author Hooman Salamat
 *  @bug No known bugs.
 */

#include <iostream>
#include <mutex>

using namespace std;

std::mutex m;

bool everything_ok()
{
    //if everything is not ok return false;
    return true;
}

void f()
{
    //do some work
    cout << "everything is just great when RAII is used!" << endl;
}

void bad()
{   // acquire the mutex
    m.lock();
    // if f() throws an exception, the mutex is never released
    f();
    // early return, the mutex is never released
    if (!everything_ok()) return;
    // if bad() reaches this statement, the mutex is released
    m.unlock();
}

void good()
{
    // RAII class: mutex acquisition is initialization
    std::lock_guard<std::mutex> lk(m); 
    // if f() throws an exception, the mutex is released
    f();            
    // early return, the mutex is released
    if (!everything_ok()) return;       
}   // if good() returns normally, the mutex is released

int main()
{
    good();
}