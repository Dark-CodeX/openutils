# CHUNKIO : The Performant I/O Library

[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)

The motivation to create this library was quite simple as when parsing large files or performing some operations on large files, the program may take very long time, thus we can reduce time taken by splitting up the file into multiple chunks and then perform operations in parallel which will significantly improve the time taken.

## Table of Contents

- [Installation](#installation)
    - [Prerequisites](#prerequisites)
    - [Install `chunkio` Header Files](#install-chunkio-header-files)
- [Usage](#usage)
    - [Example 1](#example-1)
    - [Example 2](#example-2)
- [Contributing](#contributing)
    - [Reporting Bugs](#reporting-bugs)
    - [Suggesting Enhancements](#suggesting-enhancements)
- [License](#license)

## Installation

- ### Prerequisites
    - On Debian and its derivatives
    ```bash
    $ sudo apt update
    $ sudo apt install build-essential
    ```
    - On Arch and its derivatives
    ```bash
    $ sudo pacman -Sy gcc
    ```
- ### Install `chunkio` Header Files
    - On Arch and its derivatives
    ```bash
    $ git clone https://github.com/Dark-CodeX/chunkio.git && cd ./chunkio
    $ mkdir -p package && cp PKGBUILD ./package && cd ./package && makepkg -si
    ```
    - On any other operating system
         - Download [InstallReposGUI.jar](https://github.com/Dark-CodeX/InstallRepos/releases/download/v1.1.0/InstallReposGUI.jar) or [InstallReposCLI.jar](https://github.com/Dark-CodeX/InstallRepos/releases/download/v1.1.0/InstallReposCLI.jar)
         - Run them as `administrator` or `sudo`
         ```bash
         $ java -jar ./InstallRepos<CLI/GUI>.jar
         ```
         - Once, they open up enter your installation directory and install `chunkio` library.

## Usage

Usage of this project is very practical and useful, whenever you have to perform I/O operations on very large files.

### Example 1:
```cpp
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
```

You can compile the above code as:
```bash
$ g++ -std=c++23 -g -Wall ./test.cc -o test.out
```

Now, execute the file as:
```bash
$ ./test.out
Hello World
```

### Example 2:
```cpp
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
    char *ptr = rl.read_next();

    while (ptr)
    {
        std::cout << ptr << "\n";
        ptr = rl.read_next();
    }
    return 0;
}
```

You can compile the above code as:
```bash
$ g++ -std=c++23 -g -Wall ./test.cc -o test.out
```

Now, execute the file as:
```bash
$ ./test.out
<content of './test_bytes.cc' file>
```

## Contributing

### Reporting Bugs

If you find a bug, please open an issue on the GitHub repository with a clear description of the problem. Please include any relevant information such as error messages, steps to reproduce the problem, and your operating system and compiler version.

### Suggesting Enhancements

If you have an idea for how to improve the project, please open an issue on the GitHub repository with a clear description of your proposed enhancement. Please include any relevant information such as use cases, code examples, and any related issues or pull requests.

## License

A copy of the GNU GPL v3.0 license can be found in the [LICENSE](./LICENSE) file.