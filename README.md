# VECTOR : The Resizable Array Library

[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)

## Table of Contents

- [Installation](#installation)
    - [Prerequisites](#prerequisites)
    - [Install `vector` Header Files](#install-vector-header-files)
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
- ### Install `vector` Header Files
    - On Arch and its derivatives
    ```bash
    $ git clone https://github.com/Dark-CodeX/vector.git && cd ./vector
    $ mkdir -p package && cp PKGBUILD ./package && cd ./package && makepkg -si
    ```
    - On any other operating system
         - Download [InstallReposGUI.jar](https://github.com/Dark-CodeX/InstallRepos/releases/download/v1.1.0/InstallReposGUI.jar) or [InstallReposCLI.jar](https://github.com/Dark-CodeX/InstallRepos/releases/download/v1.1.0/InstallReposCLI.jar)
         - Run them as `administrator` or `sudo`
         ```bash
         $ java -jar ./InstallRepos<CLI/GUI>.jar
         ```
         - Once, they open up enter your installation directory and install `vector` library.

## Usage

This project can be used whenever you have to manage a list of same data type variables whose length is undetermined at compile time.

### Example 1:
```cpp
#include "../vector/vector.hh"
#include <iostream>
#include <openutils/sstring/sstring.hh>

int main()
{
    using namespace openutils;
    sstring x = "HelloHello";
    vector_t<char> vec(x.begin(), x.begin() + 5);
    for (char i : vec)
        std::cout << i << "\n";
    std::cout << "LEN: " << vec.length() << "\n";
    std::cout << "CAP: " << vec.capacity() << std::endl;
    return EXIT_SUCCESS;
}
```

You can compile the above code as:
```bash
$ g++ -std=c++23 -g -Wall ./test.cc -o test.out
```

Now, execute the file as:
```bash
$ ./test.out
H
e
l
l
o
LEN: 5
CAP: 10
```

### Example 2:
```cpp
#include "../vector/vector.hh"
#include <iostream>

int main()
{
    openutils::vector_t<int> vec = {5, 11, 24, -21, -2, 1};
    vec.sort([](auto t1, auto t2)
             { return t1 < t2; });
    for (int i : vec)
        std::cout << i << "\n";
    return EXIT_SUCCESS;
}
```

You can compile the above code as:
```bash
$ g++ -std=c++23 -g -Wall ./test.cc -o test.out
```

Now, execute the file as:
```bash
$ ./test.out
-21
-2
1
5
11
24
```

## Contributing

### Reporting Bugs

If you find a bug, please open an issue on the GitHub repository with a clear description of the problem. Please include any relevant information such as error messages, steps to reproduce the problem, and your operating system and compiler version.

### Suggesting Enhancements

If you have an idea for how to improve the project, please open an issue on the GitHub repository with a clear description of your proposed enhancement. Please include any relevant information such as use cases, code examples, and any related issues or pull requests.

## License

A copy of the GNU GPL v3.0 license can be found in the [LICENSE](./LICENSE) file.