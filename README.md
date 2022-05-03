# Operating-Systems-fork-and-exec-example
This program demonstrates how to use fork() and exec() system calls in order to compare between two strings while the user gets to choose the comparison method from the methods supplied

Written in C, works on Linux bash

# The goal
Get two string from the user and compare them the way he chose when he actrivated the program with the makefile.
The mission was to do it by used fork and getting the child process to go to other program, compare the strings there, and return the result ( 1 - first is 'bigger', 2 - second is 'bigger', or 0 - eqauls) as the child exit code. Then, the parent print the exit code of the child.

# Example of the running program
![ex1_screenshot](https://user-images.githubusercontent.com/93268216/166437651-1118a78a-552f-4098-861b-0a3db00edb89.png)
