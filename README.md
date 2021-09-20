# SafeString
**Safe string implementation in C.**

This sstring struct is memory safe means that it will not cause memory leak.
**This library have most of the functions of a high level language and some functions are not even defined in high level language like `entropy`, `to_binary`, `to_hexadecimal`, `distance` and *even more*.**
**This library has 56 pre-defined functions.**
This header file is *cross-platform*, but tested only on Windows 10, Windows 11, Arch Linux, Debian Linux, WSL 2 only. (But will work on macOS also). *And checked memory leak using **`valgrind`** in which (55/56) functions passed.*

Documents are added in the header(`"sstring/sstring.h"`) file itself.
Be sure to suggest any changes.

# Functions Defined v:8.2.0

<code>set</code>

<code>set_char</code>

<code>set_upto</code>

<code>set_random</code>

<code>set_array</code>

<code>get</code>

<code>append</code>

<code>append_char</code>

<code>append_upto</code>

<code>append_start</code>

<code>append_start_char</code>

<code>append_start_upto</code>

<code>append_array</code>

<code>append_start_array</code>

<code>empty</code>

<code>replace_char</code>

<code>char_set</code>

<code>char_get</code>

<code>length</code>

<code>compare</code>

<code>compare_upto</code>

<code>print</code>

<code>replace</code>

<code>destructor</code>

<code>c_str</code>

<code>save</code>

<code>open</code>

<code>clear</code>

<code>to_upper</code>

<code>swap_case</code>

<code>to_lower</code>

<code>is_initialized</code>

<code>to_binary</code>

<code>from_binary</code>

<code>entropy</code>

<code>contains</code>

<code>contains_char</code>

<code>to_set</code>

<code>copy</code>

<code>to_hexadecimal</code>

<code>from_hexadecimal</code>

<code>find</code>

<code>in</code>

<code>getline</code>

<code>reverse</code>

<code>remove</code>

<code>remove_char</code>

<code>remove_extra_char</code>

<code>remove_range</code>

<code>intersect</code>

<code>distance</code>

<code>edit_distance</code>

<code>percentage_matched</code>

<code>count</code>

<code>count_char</code>

<code>soundex</code>

# BUILD AND INSTALL

**For testing use:** *`gcc -Os -O2 -s -Wall -ggdb3 -g -std=c17 -Wextra -pedantic -Wmissing-prototypes -Wstrict-prototypes -Wold-style-definition test.c -lm -o test` and then `valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./test "Hello World Hello!"`*

## Installation

To install on *arch linux* use **`PKGBUILD`**.

To install on *any OS* just copy and paste **`sstring`** folder in *`include`* directory of *`gcc`*.
