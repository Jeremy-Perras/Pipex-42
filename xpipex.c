/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpipex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 09:38:43 by jperras           #+#    #+#             */
/*   Updated: 2022/03/26 18:07:15 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "xpipex.h"

static char	**ft_path(char **env)
{
	size_t	i;
	char	*path;
	char	**mypath;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (!env[i])
	{
		write(2, "Path not found\n", 15);
		exit(1);
	}
	path = env[i] + 5;
	mypath = ft_split(path, ':');
	i = 0;
	while (mypath[i])
	{
		tmp = mypath[i];
		mypath[i] = ft_strjoin(mypath[i], "/");
		free(tmp);
		i++;
	}
	return (mypath);
}

char	*ft_cmd(char *comd, char **env)
{
	char	**mypath;
	char	*cmd;
	int		i;

	i = 0;
	mypath = ft_path(env);
	while (mypath[i])
	{
		cmd = ft_strjoin(mypath[i], comd);
		if (access(cmd, F_OK) == 0)
			return (cmd);
		free(cmd);
		i++;
	}
	write(2, "command not found\n", 18);
	exit(1);
}

static void	pipex(char **argv, char **env, int *i)
{
	pid_t	parent;
	int		end[2];
	int		j;
	int		fd;

	j = 2;
	fd = 0;
	while (j < i[2] - 1)
	{
		pipe(end);
		parent = fork();
		if (!parent)
		{
			dup2(fd, STDIN_FILENO);
			if (j < i[2] - 2)
				dup2(end[1], STDOUT_FILENO);
			ft_child_process(argv[j], env, end);
		}
		else
			ft_parent_process(end, &fd);
		j++;
	}
}

static void	ft_open(char **argv, int *fdin)
{
	if (access(argv[1], F_OK) == 0)
		*fdin = open(argv[1], O_RDONLY);
	else
	{
		write(2, "Error access fdin\n", 18);
		exit (1);
	}
}

int	main(int argc, char **argv, char **env)
{
	int	fdin;
	int	fdout;
	int	i[3];

	if (argc >= 5)
	{
		ft_open(argv, &fdin);
		fdout = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (fdin < 0 || fdout < 0)
			return (1);
		dup2(fdin, STDIN_FILENO);
		dup2(fdout, STDOUT_FILENO);
		i[0] = fdin;
		i[1] = fdout;
		i[2] = argc;
		pipex(argv, env, i);
	}
	else
		write(2, "Invalid arguments\n", 18);
	return (1);
}
