#ifndef MAIN_H
#define MAIN_H
#define _GNU_SCORE
#define MAX_LINE_LENGTH 1024
#define MAX_ALIAS 32
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>
#include <stdbool.h>
/**
 *struct alias - defines an alias with a name and  value
 *@name: the alias name
 *@value: the alias value
 *
 *Description: first structure
 */
struct alias
{
	char *name;
	char *value;
};
typedef struct alias Alias;
void list_aliases(void);
void define_aliases(int argCount, char **args);
int find_alias_index(const char *name);
extern char **environ;
int main(void);
void print0(void);
void print1(void);
void print2(void);
void print3(void);
void command(char *line);
void command2(char *line);
void handle_env_command(char **env);
void handle_setenv_command(const char *name, const char *value);
void handle_unsetenv_command(const char *name);
void execute_external_command(char *args[]);
void handle_cd_command(char *args[]);
char *replace_variables(char *str);
void parse_and_execute_command(const char *line, char *env[]);
char *search_path(const char *cmd, const char *path);
void execute_command(const char *command);
void execute_command4(const char *command);
void execute_command5(const char *command);
void execute_command8(const char *command);
void execute_command9(const char *command);
void execute_command10(const char *command);
void execute_command11(const char *command);
void execute_command12(char **args, bool success);
void handle_echo_command(char *line);
void execute_command13(const char *command);
void execute_command14(const char *command);
void execute_command15(const char *command);
void run_shell(void);
ssize_t custom_getline(char **lineptr, size_t *n);
int execute_single_command(char *args[]);
#endif
