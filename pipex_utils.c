/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 09:39:56 by jperras           #+#    #+#             */
/*   Updated: 2022/03/26 11:38:07 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

void	ft_child_process(char **argv, char **env, int *end)
{
	char	**flag;

	close(end[0]);
	flag = ft_split(argv[2], ' ');
	dup2(end[1], STDOUT_FILENO);
	execve(ft_cmd(flag[0], env), flag, env);
}

void	ft_parent_process(char **argv, char **env, int *end)
{
	char	**flag;

	close(end[1]);
	flag = ft_split(argv[3], ' ');
	dup2(end[0], STDIN_FILENO);
	execve(ft_cmd(flag[0], env), flag, env);
}
