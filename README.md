# SafeString
**Safe string implementation in C.**

This sstring struct is memory safe means that it will not cause memory leak.
This header file is cross-platform, but tested only on Windows 10, Windows 11, Arch Linux, Debian Linux, WSL 2 only. (But will work on macOS also). *And checked memory leak using **`valgrind`** in which (26/27) functions passed.*

Documents are added in the header(`"sstring/sstring.h"`) file itself.
Be sure to suggest any changes.


### BUILD AND INSTALL

Compiled using cmake.

Compilation command = `cmake ./CMakeLists.txt && make`

To install on arch linux use **`PKGBUILD`**.

To install on any OS just copy and paste **`sstring`** folder in `include` directory of `gcc`.

# Functions Defined

<code>set</code>

<code>set_random</code>

<code>set_array</code>

<code>get</code>

<code>append</code>

<code>append_start</code>

<code>append_array</code>

<code>append_start_array</code>

<code>empty</code>

<code>replace_char</code>

<code>char_set</code>

<code>char_get</code>

<code>length</code>

<code>compare</code>

<code>print</code>

<code>replace</code>

<code>destructor</code>

<code>c_str</code>

<code>save</code>

<code>open</code>

<code>clear</code>

<code>to_upper</code>

<code>to_lower</code>

<code>is_initialized</code>

<code>to_binary</code>

<code>from_binary</code>

<code>entropy</code>

**Watch my youtube video [YT Video](https://youtu.be/q9DUJ3hz24o)**
