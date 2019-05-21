/*
** EPITECH PROJECT, 2019
** main
** File description:
** main
*/

#include "include/my.h"

t_list *create_env(char **env)
{
	int i = 0;
	t_list *list = init_list();

	while (env[i]) {
		add_list(list, env[i]);
		i++;
	}
	return (list);
}

t_list *create_path(char *str)
{
	int i = 5;
	int b = 0;
	char *res;
	int temp = 0;
	int x = 0;
	t_list *list = init_list();

	while (str[i]) {
		if (x != 0)
			free(res);
		res = malloc(sizeof(char) * str_path_size(str, temp) + 1);
		temp = i;
		while (i < temp + str_path_size(str, temp)) {
			res[b] = str[i];
			b++;
			i++;
		}
		res[b] = '\0';
		add_list(list, res);
		b = 0;
		i++;
	}
	return (list);
}

int main(int ac, char **av, char **env)
{
	if (ac != 1)
		return (0);
	t_list *my_env = create_env(env);

	if (av[0][0] == '.') {
		while (1) {
			minishell(my_env, env);
		}
	}
	return (0);
}