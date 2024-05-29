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

static void	child_process(char **av, char **envp, int pipefd[2])
{
	int	filein;

	close(pipefd[0]);
	if ((filein = open(av[1], O_RDONLY)) == -1)
		error("open");
	if (dup2(pipefd[1], 1) == -1)
		error("dup2");
	close(pipefd[1]);
	if (dup2(filein, 0) == -1)
		error("dup2");
	execute(av[2], envp);
}

int	main(int ac, char **av, char **envp)
{
	int		pipefd[2];
	pid_t	pid;

	if (ac == 5)
	{
		if (pipe(pipefd) == -1)
			error("pipe");
		if ((pid = fork()) == -1)
			error("pid");
		if (pid == 0)
			child_process(av, envp, pipefd);
	}
	else
		ft_printf("Invalid number of arguments!");
	return (0);
}