/*
** EPITECH PROJECT, 2019
** fork
** File description:
** my_fork
*/

#include "../include/my.h"
#include <unistd.h>

int my_fork(char **tab_path, char **array_gnl, char **env, int it)
{
	int status;
	int pid = fork();

	if (pid < 0) 
		perror("ERROR CREATION PROCESS");
	if (pid == 0) {
		if (it == -3) {
			kill(-1, 84);
		 	return (1);
		}
		my_exec(tab_path, array_gnl, env, it);
	}
	else if (pid > 0) {
		waitpid(pid, &status, 0);
		if (it == -3) {
			kill(-1, 84);
		 	return (1);
		} if (status == 139) {
			my_putstr("Segmentation fault (core dumped)\n");
		} else if (status == 131) {
			my_putstr("Segmentation fault\n");
		}
	}
	return (0);
}


int my_exec(char **tab_path, char **array_gnl, char **env ,int it)
{
	char *path_gnl;

	if (it == -3) {
		exit(1);
	}
	if (it >= 0 && tab_path[it]) {
		path_gnl = my_str_gnlpath(tab_path[it], array_gnl[0]);
		if (execve(path_gnl, array_gnl, env) == -1) {
			bad_talk(array_gnl[0]);
			exit(0);
		}
			
	}
	return (0);
}