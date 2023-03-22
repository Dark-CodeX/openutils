* # SSTRING: The Safe C/C++ String Manipulation Library ![license-status](https://img.shields.io/github/license/Dark-CodeX/sstring)
	* #### **Safe string in C/C++. With huge amount of in-built functions.**
	* #### This sstring struct/class is memory safe means that it will not cause memory leak.
	* #### **This library have most of the functions of a high level language and some functions are not even defined in high level language like `entropy`, `to_binary`, `to_hexadecimal`, `parse`, `encrypt`, `distance` and *even more*.**
	* #### **This library has 91 pre-defined functions.**
	* #### This header file is *cross-platform*, but tested only on Windows 10, Windows 11, Arch Linux, Debian Linux, WSL 2 only. (But will work on macOS also). *And checked memory leak using **`valgrind`** in which (91/91) functions passed.*
	* #### Documents are in the header(`"sstring/sstring.h"`) file itself. Be sure to suggest any changes.
* # Functions Defined v:1.7.2
```
set
set_char
set_upto
set_random
set_array
get
append
append_char
append_upto
append_start
append_start_char
append_start_upto
append_array
append_start_array
empty
replace_char
char_set
char_get
last_index_of
length
compare
compare_upto
lexicographical_comparison
print
replace
destructor
c_str
save
append_file
open
clear
to_upper
swap_case
to_lower
is_initialized
to_binary
from_binary
entropy
contains
contains_char
to_set
copy
to_hexadecimal
from_hexadecimal
find
find_next
in
getline
reverse
remove
remove_char
remove_extra_char
remove_range
intersect
distance
edit_distance
percentage_matched
count
count_char
soundex
most_used
most_used_char
split
sort
open_binary
save_binary
append_binary
add_binary
print_binary
encrypt
decrypt
begin
iterator (C only)
reverse_iterator (C only)
end
to_morse_code
from_morse_code
is_digit
is_decimal
is_ascii
is_alphabetic
format_escape_sequence
insert
starts_with
ends_with
parse
from_parse_t
set_formatted
append_formatted
resize
hash
```
* # BUILD
	* #### **For testing use:** *`gcc -g -W -Wall -Wextra -Wuninitialized -Wstrict-aliasing -ggdb3 -std=c17 -Wextra -pedantic -Wmissing-prototypes -Wstrict-prototypes -Wold-style-definition samples/test.c -lm -o test` **and then** `valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=valgrind-out.txt ./test "Hello World Hello!123"`*
* # Installation
	* #### To install on *arch linux* use **`PKGBUILD`**.
	* #### To install on **any Operating System** use:
		* #### [**GUI** Download Jar File (Cross-Platform)](https://github.com/Dark-CodeX/InstallRepos/releases/download/v1.1.0/InstallReposGUI.jar)

		* #### [**CLI** Download Jar File (Cross-Platform)](https://github.com/Dark-CodeX/InstallRepos/releases/download/v1.1.0/InstallReposCLI.jar)