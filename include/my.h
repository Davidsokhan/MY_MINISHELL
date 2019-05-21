/*
** EPITECH PROJECT, 2019
** header
** File description:
** header
*/

#ifndef MYSH_H_
#define MYSH_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>

typedef struct s_list
{
    char *data;
    struct s_list *next;
} t_list;

void my_putchar(char c);
void my_putstr(char *str);
void my_show_array(char **tab);
void show_list(t_list *list);

int verrif_my_char(char c);
int line_size(char *str);
int column_size(char *str, int i);
char **my_str_to_word_array_cwd(char *str, char *cwd);

int verif_str(char *look, char *str);
void remove_from_list(t_list *node, t_list *list);
int unset_env(t_list *my_env, char *str);

int my_char_isalphanum(char c);
int	mon_compteur(char *str);
int my_wordlen(char *str, int i);
char **my_str_to_word_array(char *str);

int my_strlen(char *str);
int count_line_size(char **tab);
int count_to_set(char *str);
int count_list(t_list *list);
int path_size(char *str);

int bad_talk(char *array_gnl);
char *my_home(char **env);
int my_bash_home(char **env);
void ch_dir(char **array_gnl, char **env);

char *my_strcpy(char *str);
void free_array(char **tab);

char *to_set(char *str);
t_list *init_list(void);
t_list *add_list(t_list *list, char *str);
void set_env(t_list *env, char *str);

int str_exit(char *str, char *exit);
int my_detection(char **path, char **array_gnl, char **env);

int my_fork(char **tab_path, char **array_gnl, char **env, int it);
int my_exec(char **tab_path, char **array_gnl, char **env ,int it);

int str_path_size(char *str, int pos);
int find_path(char *data, char *str);
char *my_str_gnlpath(char *tab, char *str);
char *my_get_env(t_list *env);


char *my_prompt(void);
int detection_command(char *str, t_list *my_env);
int detect_end(char *str);
int minishell(t_list *my_env, char **env);


#endif