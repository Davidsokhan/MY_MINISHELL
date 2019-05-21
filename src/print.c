/*
** EPITECH PROJECT, 2019
** print
** File description:
** print
*/

#include "../include/my.h"

void my_putchar(char c)
{
	write(1, &c, 1);
}

void my_putstr(char *str)
{
	for (int i = 0; str[i]; i++) {
		my_putchar(str[i]);
	}
}

void my_show_array(char **tab)
{
	for (int it = 0; tab[it]; it++) {
		my_putstr(tab[it]);
		my_putchar('\n');
	}
}

void show_list(t_list *list)
{
	t_list *temp = list;

	while (temp) {
		my_putstr(temp->data);
		my_putchar('\n');
		temp = temp->next;
	}
}
