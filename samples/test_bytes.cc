#include "../chunkio/chunkio_writer.hh"
#include "../chunkio/chunkio_bytes_reader.hh"
#include <iostream>
#include <openutils/sstring/sstring.hh>

int main()
{
    openutils::sstring loc = "./testing.txt";
    openutils::sstring content = "Hello World";

    openutils::chunkio_writer<char> write(loc.c_str());
    if (!write.file_created())
    {
        std::fprintf(stderr, "err: invalid pointer\n");
        return 1;
    }
    if (!write.append_or_save(content.c_str(), content.length()))
    {
        std::fprintf(stderr, "err: could not save file\n");
        return 1;
    }

    openutils::chunkio_bytes_reader<char> read(loc.c_str(), 10);
    if (!read.file_exists())
    {
        std::fprintf(stderr, "err: invalid pointer\n");
        return 1;
    }
    char *temp_ptr = read.read_next();
    while (temp_ptr != nullptr)
    {
        content += temp_ptr;
        temp_ptr = read.read_next();
    }
    std::cout << content << "\n";

    return 0;
}