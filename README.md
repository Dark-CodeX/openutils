# HEAP-PAIR : The Pair Management Library

[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)

## Table of Contents

- [Installation](#installation)
    - [Prerequisites](#prerequisites)
    - [Install `heap-pair` Header Files](#install-heap-pair-header-files)
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
- ### Install `heap-pair` Header Files
    - On Arch and its derivatives
    ```bash
    $ git clone https://github.com/Dark-CodeX/heap-pair.git && cd ./heap-pair
    $ mkdir -p package && cp PKGBUILD ./package && cd ./package && makepkg -si
    ```
    - On any other operating system
         - Download [InstallReposGUI.jar](https://github.com/Dark-CodeX/InstallRepos/releases/download/v1.1.0/InstallReposGUI.jar) or [InstallReposCLI.jar](https://github.com/Dark-CodeX/InstallRepos/releases/download/v1.1.0/InstallReposCLI.jar)
         - Run them as `administrator` or `sudo`
         ```bash
         $ java -jar ./InstallRepos<CLI/GUI>.jar
         ```
         - Once, they open up enter your installation directory and install `heap-pair` library.

## Usage

### Example 1:
```cpp
#include "../heap-pair/heap-pair.hh"
#include <iostream>

int main()
{
    openutils::heap_pair<char *, int> pair; // for default ctor

    openutils::heap_pair<char *, int> pair_2("OPENUTILS", 100);
    std::cout << "Value of FIRST = `" << pair_2.first() << "`\n";
    std::cout << "Value of SECOND = `" << pair_2.second() << "`\n";
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
Value of FIRST = `OPENUTILS`
Value of SECOND = `100`
```

### Example 2:
```cpp
#include "../heap-pair/heap-pair.hh"
#include <openutils/sstring/sstring.hh>
#include <iostream>

int main()
{
    std::cout << "NAME 1:\n";
    openutils::heap_pair<openutils::sstring, openutils::sstring> name1("Ram", "Krishna"); 
    std::cout << "    First name = `" << name1.first() << "`\n";
    std::cout << "    Last name = `" << name1.second() << "`\n\n";

    openutils::heap_pair<openutils::sstring, openutils::sstring> name2 = openutils::heap_pair<openutils::sstring, openutils::sstring>::make_heap_pair("Tushar", "Chaurasia");
    std::cout << "NAME 2:\n";
    std::cout << "    First name = `" << name2.first() << "`\n";
    std::cout << "    Last name = `" << name2.second() << "`" << std::endl;
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
NAME 1:
    First name = `Ram`
    Last name = `Krishna`

NAME 2:
    First name = `Tushar`
    Last name = `Chaurasia`
```

## Contributing

### Reporting Bugs

If you find a bug, please open an issue on the GitHub repository with a clear description of the problem. Please include any relevant information such as error messages, steps to reproduce the problem, and your operating system and compiler version.

### Suggesting Enhancements

If you have an idea for how to improve the project, please open an issue on the GitHub repository with a clear description of your proposed enhancement. Please include any relevant information such as use cases, code examples, and any related issues or pull requests.

## License

A copy of the GNU GPL v3.0 license can be found in the [LICENSE](./LICENSE) file.