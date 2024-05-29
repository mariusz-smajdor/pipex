/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:09:43 by msmajdor          #+#    #+#             */
/*   Updated: 2024/05/20 17:09:43 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*find_path(char **envp, char *cmd)
{
	char	**paths;
	char	*path;
	char	*part;
	short	i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = -1;
	while (++i, paths[i])
	{
		part = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part, cmd);
		free(part);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
	}
	i = -1;
	while (++i, paths[i])
		free(paths[i]);
	free(paths);
	return (NULL);
}

void	execute(char *cmd1, char **envp)
{
	char	**cmd;
	char	*path;
	short	i;

	cmd = ft_split(cmd1, ' ');
	path = find_path(envp, cmd[0]);
	i = -1;
	if (!path)
	{
		while (++i, cmd[i])
			free(cmd[i]);
		free(cmd);
		error(NULL);
	}
	if (execve(path, cmd, envp) == -1)
		error(NULL);
}

void	error(const char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}
