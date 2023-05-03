# SSTRING : The String Manipulation Library

[![License: GPL v3](https://img.shields.io/badge/License-GPLv3-blue.svg)](https://www.gnu.org/licenses/gpl-3.0)

I have created the entire library for various reasons, some of which were to extend the features of the STL string library and learn more about C/C++. [Initially](https://github.com/Dark-CodeX/sstring/tree/904d396ce1a5ce9472dea18079aa05e9c769cc0d), this project was only made for C, but after some time, I have shifted its entire code to support C++20+. I have learned many concepts and theories related to optimization, memory handling, memory leaks, information theory, and more by working on this project.

## Table of Contents

- [Installation](#installation)
    - [Prerequisites](#prerequisites)
    - [Install `sstring` Header Files](#install-sstring-header-files)
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
- ### Install `sstring` Header Files
    - On Arch and its derivatives
    ```bash
    $ git clone https://github.com/Dark-CodeX/sstring.git && cd ./sstring
    $ mkdir -p package && cp PKGBUILD ./package && cd ./package && makepkg -si
    ```
    - On any other operating system
         - Download [InstallReposGUI.jar](https://github.com/Dark-CodeX/InstallRepos/releases/download/v1.1.0/InstallReposGUI.jar) or [InstallReposCLI.jar](https://github.com/Dark-CodeX/InstallRepos/releases/download/v1.1.0/InstallReposCLI.jar)
         - Run them as `administrator` or `sudo`
         ```bash
         $ java -jar ./InstallRepos<CLI/GUI>.jar
         ```
         - Once, they open up enter your installation directory and install `sstring` library.

## Usage

Usage of this project is very broad and wide, as it can be used in any condition.

### Example 1:
```cpp
#include <openutils/sstring/sstring.hh>
#include <iostream>

int main()
{
    openutils::sstring x = "Hello, World!";
    std::cout << x << std::endl; // prints Hello, World!
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
Hello, World!
```

### Example 2:
```cpp
#include <openutils/sstring/sstring.hh>
#include <iostream>

constexpr static inline bool is_between(double value, double lower_bound, double upper_bound)
{
    return (value >= lower_bound && value <= upper_bound);
}

int main(int argc, const char **argv)
{
    if (argc == 1)
    {
        std::cerr << "err: no password passed" << std::endl;
        return EXIT_FAILURE;
    }
    openutils::sstring x = argv[1];
    double pass_strength = x.password_entropy();
    if (is_between(pass_strength, 0, 28))
        std::cout << "Very Weak Password" << std::endl;
    else if (is_between(pass_strength, 29, 35))
        std::cout << "Weak Password" << std::endl;
    else if (is_between(pass_strength, 36, 59))
        std::cout << "Medium Password" << std::endl;
    else if (is_between(pass_strength, 60, 127))
        std::cout << "Strong Password" << std::endl;
    else
        std::cout << "Very Strong Password" << std::endl;
    return EXIT_SUCCESS;
}
```

You can compile the above code as:
```bash
$ g++ -std=c++23 -g -Wall ./test.cc -o test.out
```

Now, execute the file as:
```bash
$ ./test.out "password2023"
Strong Password
$ ./test.out "password"
Medium Password
$ ./test.out "pass"
Very Weak Password
```

## Contributing

### Reporting Bugs

If you find a bug, please open an issue on the GitHub repository with a clear description of the problem. Please include any relevant information such as error messages, steps to reproduce the problem, and your operating system and compiler version.

### Suggesting Enhancements

If you have an idea for how to improve the project, please open an issue on the GitHub repository with a clear description of your proposed enhancement. Please include any relevant information such as use cases, code examples, and any related issues or pull requests.

## License

A copy of the GNU GPL v3.0 license can be found in the [LICENSE](./LICENSE) file.