/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpipex.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:33:46 by jperras           #+#    #+#             */
/*   Updated: 2022/03/26 17:57:29 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef XPIPEX_H
# define XPIPEX_H
# include <unistd.h>
# include "../printf/includes/ft_printf.h"
# include <string.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <fcntl.h>

char	*ft_cmd(char *comd, char **env);
void	ft_child_process(char *argv, char **env, int *end);
void	ft_parent_process(int *end, int *fd);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t i);
#endif
