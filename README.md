# DATE-TIME : The Date/Time Management Library

[![License: BSD 3-Clause](https://img.shields.io/badge/License-BSD%203--Clause-orange.svg)](https://opensource.org/licenses/BSD-3-Clause)

The motivation to create this library was quite simple as I couldn't find any simple date/time class or struct in STL or standard library. Well, `std::time`, `std::mktime` and `std::tm` were present but they are not concise and easy to implement in long and complex code bases. The underlying implementation of these classes are very similar to C, as `time`, `mktime` and `tm` are from standard C library `time.h` header file.

## Table of Contents

- [Installation](#installation)
	- [Prerequisites](#prerequisites)
	- [Install `date-time` Header Files](#install-date-time-header-files)
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
- ### Install `date-time` Header Files
	- On Arch and its derivatives
	```bash
	$ git clone https://github.com/Dark-CodeX/date-time.git && cd ./date-time
	$ mkdir -p package && cp PKGBUILD ./package && cd ./package && makepkg -si
	```
	- On any other operating system
		 - Download [InstallReposGUI.jar](https://github.com/Dark-CodeX/InstallRepos/releases/download/v1.1.0/InstallReposGUI.jar) or [InstallReposCLI.jar](https://github.com/Dark-CodeX/InstallRepos/releases/download/v1.1.0/InstallReposCLI.jar)
		 - Run them as `administrator` or `sudo`
		 ```bash
		 $ java -jar ./InstallRepos<CLI/GUI>.jar
		 ```
		 - Once, they open up enter your installation directory and install `date-time` library.

## Usage

Usage of this project is very practical and useful, whenever you encounter with storing, formatting and validating date and time data.

### Example 1:
```cpp
#include <openutils/date-time/date.hh>
#include <iostream>

// On 16/04/2023

int main()
{
    openutils::date bday = openutils::sstring("19/10/2005");
    int days_passed = bday.days_between(openutils::date());
    std::cout << days_passed << std::endl;
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
-6388
```

### Example 2:
```cpp
#include <openutils/date-time/time.hh>
#include <iostream>

int main()
{
    openutils::time t = openutils::sstring("17:43:56");
    std::cout << "time: " << t.to_string(true) << std::endl;
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
time: 5:43:56 PM
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