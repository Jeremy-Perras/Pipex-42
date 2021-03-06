/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 09:38:43 by jperras           #+#    #+#             */
/*   Updated: 2022/03/26 11:43:00 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

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

static void	pipex(char **argv, char **env, int fdin, int fdout)
{
	pid_t	parent;
	int		end[2];

	pipe(end);
	parent = fork();
	if (parent < 0)
	{
		close(end[0]);
		close(end[1]);
		write(2, "Fork error\n", 11);
		exit(1);
	}
	if (!parent)
	{
		close(fdout);
		ft_child_process(argv, env, end);
	}
	close(fdin);
	wait(NULL);
	ft_parent_process(argv, env, end);
}

int	main(int argc, char **argv, char **env)
{
	int	fdin;
	int	fdout;

	if (argc == 5)
	{
		if (access(argv[1], F_OK) == 0)
			fdin = open(argv[1], O_RDONLY);
		else
		{
			write(2, "Error access fdin\n", 18);
			return (1);
		}
		fdout = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (fdin < 0 || fdout < 0)
			return (1);
		dup2(fdin, STDIN_FILENO);
		dup2(fdout, STDOUT_FILENO);
		pipex(argv, env, fdin, fdout);
	}
	else
		write(2, "Invalid arguments\n", 18);
	return (1);
}
