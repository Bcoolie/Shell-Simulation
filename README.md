
# Shell-Simulation
Simple simulation of shell using C language and *nix system  calls.

# How to use
Open terminal at local repository and run make, <br>
or make all if you want to test redirection of input <br>
Run program with: ./shell 

# This simulation can: 
Execute builtin shell(bash) commands, example: 
> `ls, ps, top`
 
Execute custom made commands, example: 
> `quit, cwd (current working directory), cd`

Run background process, example: 
> `top&`

Use of pipe (|), example: 
> `ls | sort`

Use of redirection (>) & (<) to a file, example:
>`ls > filename` <br>
>`./test < filename`

Kill process with terminate signal, example:
> `kill <pid>` 

# This simulation can not:
Chain commands, example:
> `ls | grep .c | sort` 

# This project tries to follow kernel coding style:
https://www.kernel.org/doc/Documentation/CodingStyle