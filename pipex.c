/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 09:38:43 by jperras           #+#    #+#             */
/*   Updated: 2022/03/25 17:02:18 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

char	**ft_path(char **env)
{
	size_t	i;
	char	*Path;
	char	**mypath;
	char 	*tmp;

	i = 0;
	tmp = NULL;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (!env[i])
		return(env);
	Path = env[i] + 5;
	mypath = ft_split(Path, ':');
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
	if (mypath == env)
	{
		ft_printf("Error1");
		exit(1);
	}
	while (mypath[i])
	{
		cmd = ft_strjoin(mypath[i],comd);
		if (access(cmd, F_OK) == 0)
			return (cmd);
		free(cmd);
		i++;
	}
	return("Error2");
}


void	pipex(char ** argv, char **env)
{
	pid_t	end;
	int		pdes[2];
	char	**flag;

	pipe(end);
	child = fork();
	if (child < 0)
	{
		close(end[0]);
		close(end[1]);
		perror("Error3");
		exit(1);
	}
	if(!child)
	{
		flag = ft_split(argv[2], ' ');
		dup2(end[0], STDOUT_FILENO);
		close(end[1]);
		execve(ft_cmd(flag[0],env), flag, env);
	}
	dup2(end[0],STDIN_FILENO);
	close(end[1]);
	wait(NULL);
	flag = ft_split(argv[3],' ');
	execve(ft_cmd(flag[0],env), flag, env);
}

int main(int argc, char **argv, char **env)
{
	int	fdin;
	int	fdout;
	
	if (argc == 5)
	{
		fdin = open(argv[1], O_RDONLY);
		fdout = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
		dup2(f1, STDIN_FILENO);
		dup2(f2, STDOUT_FILENO);
		if (f1 < 0 || f2 < 0 )
			return(-1);
		pipex(argv, env);
	}
}
