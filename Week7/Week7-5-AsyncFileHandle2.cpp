//std::async() is a function template that accepts a callback(i.e.function or function object) as an argumentand potentially executes them asynchronously.
//https://thispointer.com/c11-multithreading-part-9-stdasync-tutorial-example/
//Now let’s modify the previous code and call fetchDataFromDB() asynchronously using std::async() 
//std::async() does following things,
//It automatically creates a thread(Or picks from internal thread pool) and a promise object for us.
//Then passes the std::promise object to thread function and returns the associated std::future object.
//When our passed argument function exits then its value will be set in this promise object, so eventually return value will be available in std::future object.

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <future>
using namespace std::chrono;
std::string fetchDataFromDB(std::string recvdData)
{
    // Make sure that function takes 5 seconds to complete
    std::this_thread::sleep_for(seconds(5));
    //Do stuff like creating DB Connection and fetching Data
    return "DB_" + recvdData;
}
std::string fetchDataFromFile(std::string recvdData)
{
    // Make sure that function takes 5 seconds to complete
    std::this_thread::sleep_for(seconds(5));
    //Do stuff like fetching Data File
    return "File_" + recvdData;
}
int main()
{
    // Get Start Time
    system_clock::time_point start = system_clock::now();
    std::future<std::string> resultFromDB = std::async(std::launch::async, fetchDataFromDB, "Data");
    //Fetch Data from File
    std::string fileData = fetchDataFromFile("Data");
    //Fetch Data from DB
    // Will block till data is available in future<std::string> object.
    std::string dbData = resultFromDB.get();
    // Get End Time
    auto end = system_clock::now();
    auto diff = duration_cast <std::chrono::seconds> (end - start).count();
    std::cout << "Total Time Taken = " << diff << " Seconds" << std::endl;
    //Combine The Data
    std::string data = dbData + " :: " + fileData;
    //Printing the combined Data
    std::cout << "Data = " << data << std::endl;
    return 0;
}