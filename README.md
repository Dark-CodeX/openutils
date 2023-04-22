# ARRAY : The Non-Resizable Array Library

[![License: BSD 3-Clause](https://img.shields.io/badge/License-BSD%203--Clause-orange.svg)](https://opensource.org/licenses/BSD-3-Clause)

## Table of Contents

- [Installation](#installation)
    - [Prerequisites](#prerequisites)
    - [Install `array` Header Files](#install-array-header-files)
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
- ### Install `array` Header Files
    - On Arch and its derivatives
    ```bash
    $ git clone https://github.com/Dark-CodeX/array.git && cd ./array
    $ mkdir -p package && cp PKGBUILD ./package && cd ./package && makepkg -si
    ```
    - On any other operating system
         - Download [InstallReposGUI.jar](https://github.com/Dark-CodeX/InstallRepos/releases/download/v1.1.0/InstallReposGUI.jar) or [InstallReposCLI.jar](https://github.com/Dark-CodeX/InstallRepos/releases/download/v1.1.0/InstallReposCLI.jar)
         - Run them as `administrator` or `sudo`
         ```bash
         $ java -jar ./InstallRepos<CLI/GUI>.jar
         ```
         - Once, they open up enter your installation directory and install `array` library.

## Usage

This project can be used whenever you have to manage a list of same data type variables whose length is fixed and you just need a container with various in-built functions.

### Example 1:
```cpp
#include "../array/array.hh"
#include <openutils/sstring/sstring.hh>
#include <iostream>

int main()
{
    openutils::array_t<openutils::sstring, 5> a1 = {"tushar", "1"};
    openutils::array_t<openutils::sstring, 5> a2 = {"chaurasia", "2"};

    a1.swap(a2);

    for(auto i : a1) // contents of a2
        std::cout << i << "\n";
    
    for(auto i : a2) // contents of a1
        std::cout << i << "\n";

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
chaurasia
2
tushar
1
```

### Example 2:
```cpp
#include "../array/array.hh"
#include <iostream>

int main()
{
    openutils::array_t<int, 6> a1 = {1, -43, -2, 100, 14, 0};
    a1.sort([](auto x, auto y)
            { return x < y; });
    for (auto i : a1)
        std::cout << i << "\n";
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
-43
-2
0
1
14
100
```

## Contributing

### Reporting Bugs

If you find a bug, please open an issue on the GitHub repository with a clear description of the problem. Please include any relevant information such as error messages, steps to reproduce the problem, and your operating system and compiler version.

### Suggesting Enhancements

If you have an idea for how to improve the project, please open an issue on the GitHub repository with a clear description of your proposed enhancement. Please include any relevant information such as use cases, code examples, and any related issues or pull requests.

## License

<pre>
BSD 3-Clause License

Copyright (c) 2023, Tushar Chaurasia

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its
   contributors may be used to endorse or promote products derived from
   this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
</pre>