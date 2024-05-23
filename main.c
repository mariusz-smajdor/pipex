/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:27:00 by msmajdor          #+#    #+#             */
/*   Updated: 2024/05/20 15:21:27 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	int pipefd[2];
	pid_t pid;
	char *line;

	if (pipe(pipefd) == -1)
		error("pipe");
	if ((pid = fork()) == -1)
		error("fork");
	if (pid == 0)
	{
		close(pipefd[1]);
		while ((line = get_next_line(pipefd[0])))
		{
			ft_printf("%s", line);
			free(line);
		}
		close(pipefd[0]);
		exit(EXIT_SUCCESS);
	}
	else
	{
		close(pipefd[0]);
		write(pipefd[1], "super\n", 6);
		close(pipefd[1]);
		if (waitpid(pid, NULL, 0) == -1)
			error("waitpid");
	}
	return (0);
}