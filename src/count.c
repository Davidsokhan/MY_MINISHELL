/*
** EPITECH PROJECT, 2019
** count
** File description:
** count
*/

#include "../include/my.h"

int my_strlen(char *str)
{
	int x = 0;

	while (str[x]) {
		x++;
	}
	return (x);
}

int count_line_size(char **tab)
{
	int it = 0;

	while (tab[it]) {
		it++;
	}
	return (it);
}

int count_to_set(char *str)
{
	int it = 0;
	int b = 0;

	while (str[it] != ' ' && str[it] != '\0') {
		it++;
	}
	it++;
	while (str[it] != '\0') {
		it++;
		b++;
	}
	return (b);
}

int count_list(t_list *list)
{
	int it = 0;
	t_list *temp = list;

	while (temp) {
		temp = temp->next;
		it++;
	}
	return (it);
}

int path_size(char *str)
{
	int it = 5;
	int count = 1;

	while (str[it]) {
		if (str[it] == ':')
			count++;
		it++;
	}
	return (count);
}