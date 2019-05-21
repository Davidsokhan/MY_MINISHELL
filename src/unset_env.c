/*
** EPITECH PROJECT, 2019
** unset_env
** File description:
** unset_env
*/

#include "../include/my.h"

int verif_str(char *look, char *str)
{
	int it = 0;

	while (str[it]) {
		if (str[it] != look[it])
			return (0);
		it++;
	}
	return (1);
}

void remove_from_list(t_list *node, t_list *list)
{
	t_list *temp = list;
	while (temp->next != node) {
		temp = temp->next;
	}
	temp->next = node->next;
	free(node);
}

int unset_env(t_list *my_env, char *str)
{
	char *res = to_set(str);
	t_list *temp = my_env;

	while (temp) {
		if (verif_str(temp->data, res) == 1) {
			remove_from_list(temp, my_env);
			return (0);
		}
		temp = temp->next;
	}
	my_putstr("Not found : ");
	my_putstr(res);
	my_putchar('\n');
	return (0);
}