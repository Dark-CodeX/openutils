# VECTOR: The Safe C/C++ Vector Library
**Safe vector in C/C++. With huge amount of in-built functions.**

**This library has 22 pre-defined functions.**
This header file is *cross-platform*, but tested only on Windows 10, Windows 11, Arch Linux, Debian Linux, WSL 2 only. (But will work on macOS also). *And checked memory leak using **`valgrind`** in which (22/22) functions passed.*

Documents are in the header(`"vector/vector.h"`) file itself.
Be sure to suggest any changes.

# Functions Defined v:1.5.0

```
length
capacity
add
insert
remove
remove(nth)
empty
hash (C++ only)
compare
compare_hash
erase
erase(default_data, capacity)
get
set
reverse
find
swap
iterator
reverse_iterator
unsafe_set
unsafe_find
unsafe_remove
unsafe_resize
unsafe_get
```

# BUILD AND INSTALL

**For testing use:** *`gcc -g -W -Wall -Wextra -Wuninitialized -Wstrict-aliasing -ggdb3 -std=c17 -Wextra -pedantic -Wmissing-prototypes -Wstrict-prototypes -Wold-style-definition test.c -lm -o test` and then `valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./test "Hello World Hello ! 122"`*

## Installation

To install on *arch linux* use **`PKGBUILD`**.

To install on *any OS* just copy and paste **`vector`** folder in *`include`* directory of *`gcc`*.
