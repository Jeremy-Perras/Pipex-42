/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpipex_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 09:39:56 by jperras           #+#    #+#             */
/*   Updated: 2022/03/26 18:13:30 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "xpipex.h"

void	ft_child_process(char *argv, char **env, int *end)
{
	char	**flag;

	close(end[0]);
	flag = ft_split(argv, ' ');
	execve(ft_cmd(flag[0], env), flag, env);
}

void	ft_parent_process(int *end, int *fd)
{
	close(end[1]);
	*fd = end[0];
	wait(NULL);
}
