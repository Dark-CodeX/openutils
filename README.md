# VECTOR : The Resizable Array Library

[![License: BSD 3-Clause](https://img.shields.io/badge/License-BSD%203--Clause-orange.svg)](https://opensource.org/licenses/BSD-3-Clause)

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

 Contributing

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