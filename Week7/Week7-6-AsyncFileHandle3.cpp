#include <fstream>
#include <thread>
#include <memory>
#include <string>

#include <Windows.h> // for SetThreadAffinityMask()
//
//void stress_write(unsigned bytes, int num)
//{
//    std::ofstream out("temp" + std::to_string(num));
//    for (unsigned i = 0; i < bytes; ++i)
//    {
//        out << char(i);
//    }
//}

void stress_write(unsigned bytes, int num)
{
    //we group writes up to 4096 bytes before sending to the std ofstream.
    constexpr auto chunk_size = (1u << 12u); // tune as needed
    std::ofstream out("temp" + std::to_string(num));
    for (unsigned chunk = 0; chunk < (bytes + chunk_size - 1) / chunk_size; ++chunk)
    {
        char chunk_buff[chunk_size];
        auto count = (std::min)(bytes - chunk_size * chunk, chunk_size);
        for (unsigned j = 0; j < count; ++j)
        {
            unsigned i = j + chunk_size * chunk;
            chunk_buff[j] = char(i); // processing
        }
        out.write(chunk_buff, count);
    }
}

void lock_thread(unsigned core_idx)
{
    SetThreadAffinityMask(GetCurrentThread(), 1LL << core_idx);
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    lock_thread(0);

    //Returns the number of concurrent threads supported by the implementation. The value should be considered only a hint.
    auto worker_count = std::thread::hardware_concurrency() - 1;

    std::unique_ptr<std::thread[]> threads = std::make_unique<std::thread[]>(worker_count); // faster than std::vector

    for (int i = 0; i < worker_count; ++i)
    {
        threads[i] = std::thread(
            [](unsigned idx) {
                lock_thread(idx);
                stress_write(1'000'000'000, idx);
            },
            i + 1
                );
    }
    stress_write(1'000'000'000, 0);

    for (int i = 0; i < worker_count; ++i)
    {
        threads[i].join();
    }
}