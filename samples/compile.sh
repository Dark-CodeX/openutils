#!/bin/bash
mkdir "./build"

for f in *c; do
    gcc -g $f -lm -o ./build/"$f".out
done
