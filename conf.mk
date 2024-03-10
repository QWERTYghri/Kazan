# Compilation Config File
#
# File for different options for compilation
# Select options and certain flags you wish to change if needed

# General Flags
CC	 := gcc
CFLAGS	 := -std=gnu99 -Wpedantic -Wall -Wextra -pipe
CPPFLAGS := -D_POSIX_C_SOURCE=200809L

# Optimization
OFLAGS	 := -g -O0
#OFLAGS	 := -Os

# Library

