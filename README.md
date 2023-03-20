* # ARRAY: The Safe C++ Array Library ![license-status](https://img.shields.io/github/license/Dark-CodeX/array)
	* #### **Safe array in C++, with huge amount of in-built functions.**
	* #### **This library has 14 pre-defined functions.**
	* #### **This library can be used in C++.**
	* #### This header file is *cross-platform*, but tested only on Windows 10, Windows 11, Arch Linux, Debian Linux, WSL 2 only. (But will work on macOS also). *And checked memory leak using **`valgrind`** in which (14/14) functions passed.*

* # Functions Defined v:1.0.0
```
add
remove
length
capacity
reverse
erase
empty
get
set
hash
compare
compare_hash
raw_data
sort
```

* # BUILD
	* #### **For testing use:** *`g++ -g -W -Wall -Wextra -std=c++20 ./samples/test.cc -o test` **and then** `valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./samples/test`*
* # Installation
	* #### To install on *arch linux* use **`PKGBUILD`**.
	* #### To install on **any Operating System** use:
		* #### [**GUI** Download Jar File (Cross-Platform)](https://github.com/Dark-CodeX/InstallRepos/releases/download/v1.1.0/InstallReposGUI.jar)

		* #### [**CLI** Download Jar File (Cross-Platform)](https://github.com/Dark-CodeX/InstallRepos/releases/download/v1.1.0/InstallReposCLI.jar)
