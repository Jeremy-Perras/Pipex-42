/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jperras <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 08:38:35 by jperras           #+#    #+#             */
/*   Updated: 2022/03/25 14:08:39 by jperras          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{	
	size_t			i;
	unsigned char	*str;
	unsigned char	*str2;

	i = 0;
	str = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while (str[i] == str2[i] && str[i] != '\0' && str2[i] != '\0' && i < n - 1)
		i++;
	return (str[i] - str2[i]);
}
