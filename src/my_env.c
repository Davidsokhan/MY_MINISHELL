/*
** EPITECH PROJECT, 2019
** my_env
** File description:
** env
*/

#include "../include/my.h"

char *to_set(char *str)
{
	int it = 0;
	int b = 0;
	int count;
	char *res;

	if ((count = count_to_set(str)) == 0)
		exit(1);
	res = malloc(sizeof(char) * count);
	while (str[it] != ' ' && str[it] != '\0') {
		it++;
	}
	it++;
	while (str[it] != '\0' && str[it] != '\n') {
		res[b] = str[it];
		it++;
		b++;
	}
	res[b] = '\0';
	return (res);
}

t_list *init_list(void)
{
	t_list *list;
	if ((list = malloc(sizeof(t_list))) == NULL)
		return (NULL);
	list->next = NULL;
	list->data = NULL;
	return (list);
}

t_list *add_list(t_list *list, char *str)
{
	t_list *temp;
	t_list *news;

	temp = list;
	if (temp->data == NULL){
		temp->data = str;
		return (list);
	} else {
		while (temp->next != NULL) {
			temp = temp->next;
		}
		news = init_list();
		news->data = my_strcpy(str);
		temp->next = news;
		return (list);
	}
}

void set_env(t_list *env, char *str)
{
	char *res = to_set(str);

    add_list(env, res);
}