/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:52:32 by pcoureau          #+#    #+#             */
/*   Updated: 2020/10/06 15:17:42 by paco             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int		ft_switch(char **s, char **tmp)
{
	if (*s)
		free(*s);
	if (!(*s = ft_strdupgnl(*tmp)))
	{
		free(*tmp);
		return (-1);
	}
	free(*tmp);
	return (1);
}

void	ft_advance(char *buff, int i)
{
	int j;

	j = 0;
	i++;
	while (buff[i] != '\0')
	{
		buff[j] = buff[i];
		i++;
		j++;
	}
	buff[j] = '\0';
}

int		ft_rline(char **line, char *s, char *buff, int i)
{
	if (!(*line = ft_strdcpy(s)))
	{
		if (*s)
			free(s);
		return (-1);
	}
	free(s);
	ft_advance(buff, i);
	return (1);
}

int		ft_end(char **line, char *s, int err)
{
	if (err == 0 || !(*line = ft_strdcpy(s)))
	{
		if (*s)
			free(s);
		return (-1);
	}
	free(s);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	char		*s;
	int			ret;
	static char	buff[250][32 + 1];
	char		*tmp;
	int			i;

	if (!(s = ft_strdupgnl(buff[fd])))
		return (-1);
	if ((i = ft_strchrbn(buff[fd])) >= 0)
		return (ft_rline(line, s, buff[fd], i));
	while ((ret = read(fd, buff[fd], 32)) >= 0)
	{
		buff[fd][ret] = '\0';
		if (!(tmp = ft_strjoin(s, buff[fd])))
			return (ft_end(line, s, 0));
		if (ft_switch(&s, &tmp) < 0)
			return (-1);
		if (ret == 0)
			return (ft_end(line, s, 1));
		if ((i = ft_strchrbn(buff[fd])) >= 0)
			return (ft_rline(line, s, buff[fd], i));
	}
	free(s);
	return (-1);
}
