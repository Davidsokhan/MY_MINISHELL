/*
** EPITECH PROJECT, 2019
** my_exec
** File description:
** my execve
*/

#include "../include/my.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int str_exit(char *str, char *exit)
{
	int i = 0;
	
	 while(str[i] != '\0' || exit[i] != '\0') {
	 	if (str[i] != exit[i]) {
	 		return (0);
	 	}
	 	i = i + 1;
	}
	return (1);
}

int my_detection(char **path, char **array_gnl, char **env)
{
	int y = 0;
	char *temp;
	if (array_gnl[0] == NULL) {
	 	return (-1);
	}
	if (str_exit(array_gnl[0], "exit") == 1) {
		exit(-3);
	}

	if (str_exit(array_gnl[0], "cd") == 1) {
		return(-4);
	}

	if (str_exit(array_gnl[0], "~") == 1) {
		my_bash_home(env);
		return(-20);
	}
		
	while (path[y]) {
		temp = my_str_gnlpath(path[y], array_gnl[0]);
		if (open(temp, O_RDONLY) != - 1) {
			return (y);
		}
		y = y + 1;
	}
	return (-2);
}
