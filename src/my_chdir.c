/*
** EPITECH PROJECT, 2019
** my_chdir
** File description:
** chdir
*/
#include "../include/my.h"

int bad_talk(char *array_gnl)
{
	my_putstr(array_gnl);
	my_putstr(": command not found\n");
	return (0);
}

char *my_home(char **env)
{
	char *str = NULL;
	int b = 0;
	int it = 0;
	int x = 0;
	int l = 0;
	
	while (env[x]) {
		if (env[x][0]=='H' && env[x][1]== 'O' && env[x][2] == 'M' && env[x][3] == 'E' && env[x][4] == '=') {
			while (env[x][it] != '=' && env[x][it] != '\0') {
				it = it + 1;
			}
			it = it + 1;
			l = my_strlen(env[x]) - it;
			str = malloc(sizeof(char)* l + 1);
			while (env[x][it] != '\0') {
				str[b] = env[x][it];
				b = b + 1;
				it = it + 1;
			}
			str[b] = '\0';
			return (str);
		}
		x = x + 1;
	}
	return (str);
}
int my_bash_home(char **env)
{
	char *home = my_home(env);
	my_putstr("bash : ");
	my_putstr(home);
	my_putstr(": Is a directory\n");
	return(0);
}

void ch_dir(char **array_gnl, char **env)
{
	int i = 0;
	if (array_gnl[0][0] == '~' || array_gnl[1] == NULL) {
		i = 1;
		chdir(my_home(env));
	}
	if (chdir(array_gnl[1]) == -1 && i == 0)
		perror("bash: cd");
} 