# SSTRING: The Safe C String Manipulation Library
**Safe string in C. With huge amount of in-built functions.**

This sstring struct is memory safe means that it will not cause memory leak.
**This library have most of the functions of a high level language and some functions are not even defined in high level language like `entropy`, `to_binary`, `to_hexadecimal`, `distance` and *even more*.**
**This library has 81 pre-defined functions.**
This header file is *cross-platform*, but tested only on Windows 10, Windows 11, Arch Linux, Debian Linux, WSL 2 only. (But will work on macOS also). *And checked memory leak using **`valgrind`** in which (81/81) functions passed.*

Documents are in the header(`"sstring/sstring.h"`) file itself.
Be sure to suggest any changes.

# Functions Defined v:34.0.0

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

<code>append_file</code>

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

<code>positional_average</code>

<code>positional_modulus</code>

<code>count</code>

<code>count_char</code>

<code>soundex</code>

<code>most_used</code>

<code>most_used_char</code>

<code>split</code>

<code>sort</code>

<code>open_binary</code>

<code>save_binary</code>

<code>append_binary</code>

<code>add_binary</code>

<code>print_binary</code>

<code>encrypt</code>

<code>decrypt</code>

<code>begin</code>

<code>iterator</code>

<code>end</code>

<code>to_morse_code</code>

<code>from_morse_code</code>

<code>is_digit</code>

<code>is_decimal</code>

<code>is_ascii</code>

<code>is_alphabetic</code>

<code>format_escape_sequence</code>

<code>insert</code>

# BUILD AND INSTALL

**For testing use:** *`gcc -Os -O3 -s -W -Wall -Wextra -Wuninitialized -Wstrict-aliasing -ggdb3 -g -std=c17 -Wextra -pedantic -Wmissing-prototypes -Wstrict-prototypes -Wold-style-definition samples/test.c -lm -o test` and then `valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./test "Hello World Hello!"`*

## Installation

To install on *arch linux* use **`PKGBUILD`**.

To install on *any OS* just copy and paste **`sstring`** folder in *`include`* directory of *`gcc`*.
