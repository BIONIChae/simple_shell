#ifndef UNIX_H
#define UNIX_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define SHELL_NAME "hsh"
#define MAX_ARGS 1024

extern char **environ;

void split_str(char *str, char delim);
int _exiting_(int count, char **vec);
int print_env(void);
int exiting(void);
ssize_t getline_from_scratch(char **read_line, size_t *buf_size);
int handle_args(int count, char **vec);
int in_path(char *path);
void split_str(char *str, char delim);
int interpret(char *cmd_input);

int setenv(char *variable, char *value, int overwrite);
int unsetenv(char *variable);
int cd(char **argv);
int handle_command_file(char *filename);
int handle_comments(char **args);
int handle_variables(char **args);
int alias(char **args);

int main(void);

#endif
