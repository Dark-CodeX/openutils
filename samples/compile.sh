#!/bin/bash
mkdir "./build"

for f in *c; do
    gcc -g -W -Wall -Wextra -Wuninitialized -Wstrict-aliasing -ggdb3 -std=c17 -Wextra -pedantic -Wmissing-prototypes -Wstrict-prototypes -Wold-style-definition $f -lm -o ./build/"$f".out
done
