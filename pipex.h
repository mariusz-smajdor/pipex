/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msmajdor <msmajdor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:27:03 by msmajdor          #+#    #+#             */
/*   Updated: 2024/05/19 15:59:50 by msmajdor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libs/libft/libft.h"
# include "libs/ft_printf/libftprintf.h"
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>

void	error(const char *msg);
void	execute(char *cmd1, char **envp);

#endif
