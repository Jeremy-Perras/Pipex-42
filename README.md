# Pipex-42

## Table of content :
* [What is printf ?](#what-is-pipex-)
* [What is in it ?](#what-is-in-it-)
* [How does is work ?](#how-does-is-work-)

### What is pipex ?
 Pipex is a individual project at 42 re-create  
 > < file1 cmd1 | cmd2 > file2 
 As you do in your shell.
 
 The purpose is too learn more about fork, pipe, wait.
 
### How does is work ?
The Makefile contain 4 rules : all clean fclean and re.
Make create a program called pipex.
>$> ./pipex < file1 cmd1 | cmd2 > file2.

Make bonus create a program called pipex.
> $> ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
