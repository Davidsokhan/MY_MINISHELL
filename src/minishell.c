/*
** EPITECH PROJECT, 2019
** minishell
** File description:
** minishell
*/

#include "../include/my.h"

#include <unistd.h>

char *my_prompt(void)
{
	char *str;
	char *result;
    size_t len = 0;
    int it = 0;

    my_putstr("$>");
    result = malloc(sizeof(char) * getline(&str, &len, stdin));
    while (str[it]) {
    	result[it] = str[it];
    	it++;
    }
    result[it] = '\0';
    return (result);
}

int detection_command(char *str, t_list *my_env)
{
	if (str[0] == 's' && str[1] == 'e' && str[2] == 't' 
		&& str[3] == 'e' && str[4] == 'n' && str[5] == 'v') {
		set_env(my_env, str);
		return (1);
	}
	if (str[0] == 'u' && str[1] == 'n' && str[2] == 's' && str[3] == 'e' 
		&& str[4] == 't' && str[5] == 'e' && str[6] == 'n' && str[7] == 'v') {
		unset_env(my_env, str);
		return (1);
	}
	return (0);
}

int detect_end(char *str)
{
	if (str[0] == 'e' && str[1] == 'x' && str[2] == 'i' 
		&& str[3] == 't' && str[4] == '\0')
		return (1);
	return (0);
}

int minishell(t_list *my_env, char **env)
{
	char *command = NULL;
	char **array_gnl;
	char my_cwd[256];
	char **tab_path;
	char *str_path = my_get_env(my_env);
	char *cwd;
	int it;

	(getcwd(my_cwd, sizeof(my_cwd)) == NULL)? perror("getcwd() error") : 1;
	cwd = my_strcpy(my_cwd);
	command = my_prompt();
	tab_path = my_str_to_word_array_cwd(str_path, cwd);
	array_gnl = my_str_to_word_array(command);
	it = my_detection(tab_path, array_gnl, env);
	if (detect_end(command) == 1)
		return (0);
	if (detection_command(command, my_env) == 1)
		return (0);
	if (command[0] == 'e' && command[1] == 'n' && command[2] == 'v') {
		show_list(my_env);
		return (0);
	}
	(it == -3) ? exit(1) : 1;
	(it == -4) ? ch_dir(array_gnl, env) : 1; 
	(it == -2) ? bad_talk(array_gnl[0]) : 1;
	(it != -2) ? my_fork(tab_path, array_gnl, env, it) : 1;
	return (0);
}