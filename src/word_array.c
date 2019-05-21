/*
** EPITECH PROJECT, 2019
** word_array
** File description:
** word_array
*/

#include "../include/my.h"

int my_char_isalphanum(char c)
{
	if (c < '!' || (c > '9' && c < 'A') ||
            (c > 'Z' && c < 'a') || c > 'z' ) {
	        return(0);
	}
	return(1);
}
int	mon_compteur(char *str)
{
	int	a = 0;
	int	b = 0;
	while (str[a] != '\0'){
		if (my_char_isalphanum(str[a]) == 1 &&
            my_char_isalphanum(str[a + 1]) != 1){
			b = b + 1;
		}
		a = a + 1;
	}
	return (b);
}

int my_wordlen(char *str, int i)
{
    while (str[i] != '\0') {
            if (my_char_isalphanum(str[i]) != 1)
                    return (i);
            i++;
    }
    return (i);
}


char **my_str_to_word_array(char *str)
{
	int	y = mon_compteur(str);
	char **argv = malloc(sizeof(char *) * y + 1);
	int	a = 0;
	int	b = 0;
	int	c = 0;

	
	while (b < y){
		c = 0;
        while  (str[a] && my_char_isalphanum(str[a]) != 1)
            a = a + 1;
		argv[b] = malloc(sizeof(char) * my_wordlen(str, a) + 1);
		while (str[a] != '\0' && my_char_isalphanum(str[a]) != 0) {
			argv[b][c] = str[a];
			c = c + 1;
			a = a + 1;
		}
		argv[b][c] = '\0';
		a = a + 1;
		b = b + 1;
	}
    argv[b] = NULL;
	return (argv);
}
