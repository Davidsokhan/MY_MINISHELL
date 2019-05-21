/*
** EPITECH PROJECT, 2019
** tab
** File description:
** tab
*/

#include "../include/my.h"

int verrif_my_char(char c)
{
	if (c == ':')
		return(1);
	return (0);
}

int line_size(char *str)
{
	int i = 0;
	int count = 1;

	while (str[i]) {
		if (str[i] == ':')
			count++;
		i++;
	}
	return (count);
}

int column_size(char *str, int i)
{
	int count = 0;

	while (str[i]) {
		if (verrif_my_char(str[i]) == 1)
			return (count);
		i++;
		count++;
	}
	return (count);
}

char **my_str_to_word_array_cwd(char *str, char *cwd)
{
	char **tab = malloc(sizeof(char *) * (line_size(str) + 3));
	int it = 0;
	int b = 0;
	int x = 5;

	while (it < line_size(str) && str[x]) {
		tab[it] = malloc(sizeof(char) * (column_size(str, x) + 1));
		while (str[x] != ':' && str[x]) {
			tab[it][b] = str[x];
			b++;
			x++;
		}
		x++;
		tab[it][b] = '\0';
		b = 0;
		it++;
	}
	x = 0;
	tab[it] = malloc(sizeof(char) * my_strlen(cwd) + 1);
	while (cwd[x]) {
		tab[it][b] = cwd[x];
		b++;
		x++;
	}
	tab[it][b] = '\0';
	tab[it + 1] = NULL;
	return (tab);
}