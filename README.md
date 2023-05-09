# MTHREAD : The Multi-Threading Library

[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)

The motivation to create this library was quite simple as I had to increase my app's (`runcpp`) performance for larger input files.

## Table of Contents

- [Installation](#installation)
    - [Prerequisites](#prerequisites)
    - [Install `mthread` Header Files](#install-mthread-header-files)
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
- ### Install `mthread` Header Files
    - On Arch and its derivatives
    ```bash
    $ git clone https://github.com/Dark-CodeX/mthread.git && cd ./mthread
    $ mkdir -p package && cp PKGBUILD ./package && cd ./package && makepkg -si
    ```
    - On any other operating system
         - Download [InstallReposGUI.jar](https://github.com/Dark-CodeX/InstallRepos/releases/download/v1.1.0/InstallReposGUI.jar) or [InstallReposCLI.jar](https://github.com/Dark-CodeX/InstallRepos/releases/download/v1.1.0/InstallReposCLI.jar)
         - Run them as `administrator` or `sudo`
         ```bash
         $ java -jar ./InstallRepos<CLI/GUI>.jar
         ```
         - Once, they open up enter your installation directory and install `mthread` library.

## Usage

Usage of this project is very practical and useful, whenever you have to deal with multi-threading.

### Example 1:
```cpp
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
```

You can compile the above code as:
```bash
$ g++ -std=c++23 -g -Wall ./test.cc -o test.out
```

Now, execute the file as:
```bash
$ ./test.out
70
81
MAX THREADS = 16 // May vary on your system
```

### Example 2:
```cpp
#include "../mthread/mthread.hh"

void *print()
{
    std::printf("hello world\n");
    return nullptr;
}

int main()
{
    using namespace openutils;
    mthread<void *> thread;
    thread.execute_processes({print});
}
```

You can compile the above code as:
```bash
$ g++ -std=c++23 -g -Wall ./test.cc -o test.out
```

Now, execute the file as:
```bash
$ ./test.out
hello world
```

## Contributing

### Reporting Bugs

If you find a bug, please open an issue on the GitHub repository with a clear description of the problem. Please include any relevant information such as error messages, steps to reproduce the problem, and your operating system and compiler version.

### Suggesting Enhancements

If you have an idea for how to improve the project, please open an issue on the GitHub repository with a clear description of your proposed enhancement. Please include any relevant information such as use cases, code examples, and any related issues or pull requests.

## License

A copy of the GNU GPL v3.0 license can be found in the [LICENSE](./LICENSE) file.