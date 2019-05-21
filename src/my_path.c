/*
** EPITECH PROJECT, 2019
** my_path
** File description:
** find the path
*/

#include "../include/my.h"

int str_path_size(char *str, int pos)
{
	int count = 0;

	while (str[pos] != ':' && str[pos]) {
		pos++;
		count++;
	}
	return (count);
}

int find_path(char *data, char *str)
{
	int i = 0;

	while (str[i]) {
		if (str[i] != data[i])
			return (1);
		i++;
	}
	return (0);
}

char *my_str_gnlpath(char *tab, char *str)
{
	int x = 0;
	int y = 0;
	int i = my_strlen(tab) + my_strlen(str);
	char *line = malloc(sizeof(char)* i + 2);

	while (tab[x] != '\0') {
		line[x] = tab[x];
		x = x + 1;
	}
	line[x] = '/';
	x = x + 1;
	while (str[y] != '\0') {
		line[x] = str[y];
		x = x + 1;
		y = y + 1;
	}
	line[x] = '\0';
	return (line);
}

char *my_get_env(t_list *env)
{
	t_list *temp = env;
	char *str = NULL;

	while (temp) {
		if (temp->data[0] == 'P' && temp->data[1] == 'A' && temp->data[2] == 'T' 
			&& temp->data[3] == 'H' && temp->data[4] == '=') {
			str = my_strcpy(temp->data);
			return (str);
		}
		temp = temp->next;
	}
	return (str);
}