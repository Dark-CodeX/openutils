#include "../chunkio/chunkio_writer.hh"
#include "../chunkio/chunkio_lines_reader.hh"
#include <iostream>
#include <openutils/sstring/sstring.hh>

int main()
{
    openutils::chunkio_lines_reader<char> rl("./test_bytes.cc", 1);
    if (!rl.file_exists())
    {
        std::fprintf(stderr, "err: invalid pointer\n");
        return 1;
    }
    char *ptr = rl.read_next().first;
    while (ptr)
    {
        std::cout << ptr << "\n";
        ptr = rl.read_next().first;
    }
    return 0;
}