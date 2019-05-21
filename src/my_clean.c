/*
** EPITECH PROJECT, 2019
** clean
** File description:
** clean
*/

#include "../include/my.h"

char *my_strcpy(char *str)
{
	char *cpy = malloc(sizeof(char) * my_strlen(str) + 1);
	int it = 0;

	while (str[it]) {
		cpy[it] = str[it];
		it++;
	}
	cpy[it] = '\0';
	return (cpy);
}