# MAP : The Unique Element Container Library [NOT-MAINTAINED]

[![License: BSD 3-Clause](https://img.shields.io/badge/License-BSD%203--Clause-orange.svg)](https://opensource.org/licenses/BSD-3-Clause)

## Table of Contents

- [Installation](#installation)
    - [Prerequisites](#prerequisites)
    - [Install `map` Header Files](#install-map-header-files)
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
- ### Install `map` Header Files
    - On Arch and its derivatives
    ```bash
    $ git clone https://github.com/Dark-CodeX/map.git && cd ./map
    $ mkdir -p package && cp PKGBUILD ./package && cd ./package && makepkg -si
    ```
    - On any other operating system
         - Download [InstallReposGUI.jar](https://github.com/Dark-CodeX/InstallRepos/releases/download/v1.1.0/InstallReposGUI.jar) or [InstallReposCLI.jar](https://github.com/Dark-CodeX/InstallRepos/releases/download/v1.1.0/InstallReposCLI.jar)
         - Run them as `administrator` or `sudo`
         ```bash
         $ java -jar ./InstallRepos<CLI/GUI>.jar
         ```
         - Once, they open up enter your installation directory and install `map` library.

## Usage

This project can be used whenever you have to manage a unique pair of KEY and VALUE whose length is undetermined at compile time.

### Example 1:
```cpp
#include "../map/map.hh"
#include <iostream>
#include <openutils/sstring/sstring.hh>

int main(int argc, char const **argv)
{
	using namespace openutils;
	map_t<sstring, int> map;
	for (std::size_t i = 1; i < (std::size_t)argc; ++i)
		map.add(argv[i], i);
	for (map_t<sstring, int>::iter i = map.iterator(); i.c_loop() != false; i.next())
		std::cout << i->key << " " << i->value << std::endl;
	std::cout << "------------------------------------------" << std::endl;
	std::cout << "Length = " << map.length() << std::endl;
	std::cout << "Capacity = " << map.capacity() << std::endl;
	std::cout << "Max Depth = " << map.max_depth() << std::endl;
	std::cout << "HASH = " << std::hash<map_t<sstring, int>>()(map) << std::endl;
	std::cout << "Error Rate = " << map.error_rate(argc - 1) << "%" << std::endl;
	return 0;
}
```

You can compile the above code as:
```bash
$ g++ -std=c++23 -g -Wall ./test.cc -o test.out
```

Now, execute the file as:
```bash
$ ./test.out Tushar Chaurasia Hello World CPP C Damm Map
Tushar 1
Chaurasia 2
Hello 3
World 4
CPP 5
C 6
Damm 7
Map 8
------------------------------------------
Length = 8
Capacity = 16
Max Depth = 3
HASH = 7478833748383764968
Error Rate = 0%
```

### Example 2:
```cpp
#include "../map/map.hh"
#include <openutils/sstring/sstring.hh>
#include <iostream>

int main()
{
	using namespace openutils;
	map_t<sstring, int> x = {{"Tushar", 2}, {"Chaurasia", 3}, {"Hello", 1}, {"Bye", 123}, {"TATA", 13}};
	for (map_t<sstring, int>::iter i = x.iterator(); i.c_loop(); i.next())
		std::cout << i->key << " :: " << i->value << "\n";

	std::cout << std::endl;

   x.sort_values([](node_t<sstring, int> a, node_t<sstring, int> b)
				 { return a.value < b.value; });

	for (map_t<sstring, int>::iter i = x.iterator(); i.c_loop(); i.next())
		std::cout << i->key << "  :: " << i->value << "\n";
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
Tushar :: 2
Chaurasia :: 3
Hello :: 1
Bye :: 123
TATA :: 13

Hello  :: 1
Tushar  :: 2
Chaurasia  :: 3
TATA  :: 13
Bye  :: 123
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