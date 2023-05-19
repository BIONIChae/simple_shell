#ifndef UNIX_H
#define UNIX_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <stddef.h>

#define STDOUT_FD 1
#define STDERR_FD 2
#define SHELL_NAME "hsh"
#define MAX_ARGS 1024
#define SIZE 512

extern char **environ;


int _exiting_(int count, char **vec);
int print_env(void);
int exiting(void);
ssize_t getline_from_scratch(char **read_line, size_t *size_of_buf);
int call_getline(void);
int handle_args(int count, char **vec);
int in_path(char *path);
char split_str(char *str, char delim);
int interpret(char *cmd_input);

int my_setenv(const char *variable, const char *value, int overwrite);
int my_unsetenv(const char *variable);
int cd(char **argv);
int handle_command_file(char *filename);
int handle_comments(char (*args)[1024]);
int handle_variables(char (*args)[1024]);
int alias(char **args);
int main(void);
#endif
