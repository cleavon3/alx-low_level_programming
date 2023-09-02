#!/bin/bash

# Compile all .c files in the current directory into object files with GCC.
gcc -Wall -pedantic -Werror -Wextra -c *.c

# Create a static library by archiving all object files into liball.a.
ar -rc liball.a *.o

# Generate an index for the static library.
ranlib liball.a
