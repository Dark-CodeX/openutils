# SafeString
**Safe string implementation in C.**

This sstring struct is memory safe means that it will not cause memory leak.
This header file is cross-platform, but tested only on Windows 10, Windows 11, Arch Linux, Debian Linux, WSL 2 only. (But will work on macOS also). *And checked memory leak using **`valgrind`** in which (27/28) functions passed.*

Documents are added in the header(`"sstring/sstring.h"`) file itself.
Be sure to suggest any changes.


### BUILD AND INSTALL

Compiled using cmake.

Compilation command = `cmake ./CMakeLists.txt && make`

To install on arch linux use **`PKGBUILD`**.

To install on any OS just copy and paste **`sstring`** folder in `include` directory of `gcc`.

**Watch my youtube video [YT Video](https://youtu.be/q9DUJ3hz24o)**
