/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:52:45 by pcoureau          #+#    #+#             */
/*   Updated: 2020/02/14 02:30:45 by pcoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlengnl(char const *s)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdupgnl(const char *s)
{
	char	*dest;
	int		i;

	i = 0;
	if (!(dest = malloc(sizeof(char) * (ft_strlengnl(s) + 1))))
		return (NULL);
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdcpy(const char *s)
{
	char	*dest;
	int		i;

	i = 0;
	if (!s || !(dest = malloc(sizeof(char) * (ft_strlengnl(s) + 1))))
		return (NULL);
	while (s[i] && s[i] != '\n')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		ft_strchrbn(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i] != '\0')
	{
		if (s[i] == '\n')
		{
			return (i);
		}
		i++;
	}
	return (-1);
}
/*
char	*ft_strjoingnl(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		lens1;
	int		lens2;
	char	*p;

	i = 0;
	j = 0;
	lens1 = ft_strlengnl(s1);
	lens2 = ft_strlengnl(s2);
	if (!s2 || !(p = malloc(sizeof(char) * (lens1 + lens2 + 1))))
		return (NULL);
	while (s1 && s1[i])
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		p[i] = s2[j];
		j++;
		i++;
	}
	p[i] = '\0';
	return (p);
}
*/
