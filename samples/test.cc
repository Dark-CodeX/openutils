#include "../mthread/mthread.hh"

int main()
{
    using namespace openutils;
    mthread<int, std::pair<int, int>> thread;
    thread.execute_processes
    (
        {
            [](const std::pair<int, int> &x){ return x.first + x.second;},
            [](const std::pair<int, int> &x){ return x.first - x.second;}
        },

        {
            {20, 50}, {100, 19}
        }
    );

    vector_t<int> vals = thread.get();
    for(const int &i : vals)
    {
        std::printf("%d\n", i);
    }

    std::printf("MAX THREADS = %u\n", mthread<void *>::max_threads());

    return 0;
}