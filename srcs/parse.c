/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 11:54:16 by pcoureau          #+#    #+#             */
/*   Updated: 2020/11/03 16:41:23 by paco             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_color			ft_color(t_struct *s, char *line)
{
	t_color			color;
	char			**tab;
	int				i;

	i = 0;
	s->i += 1;
	tab = ft_split(&line[s->i], ',');
	while (tab[i])
		i++;
	if (i != 3)
		ft_errorl(s, 4, line);
	ft_checkcolor(s, tab);
	color.r = ft_atoi((const char *)tab[0]);
	color.g = ft_atoi((const char *)tab[1]);
	color.b = ft_atoi((const char *)tab[2]);
	while (i >= 0)
		free(tab[i--]);
	free(tab);
	if (color.r > 255 || color.r < 0 || color.g > 255 || color.g < 0 ||
			color.b > 255 || color.b < 0)
		ft_errorl(s, 4, line);
	s->parse.color++;
	return (color);
}

unsigned int	*ft_load_tex(t_struct *s, char *line)
{
	void			*ptr;
	int				tmp[5];
	unsigned int	*adr;
	char			**tab;
	int				i;

	i = 0;
	s->i += 2;
	s->line = line;
	tab = ft_split(&line[s->i], ' ');
	while (tab[i])
		i++;
	if (i != 1)
		ft_te(s, tab, 1, i);
	ptr = mlx_xpm_file_to_image(s->mlx, tab[0], &tmp[0], &tmp[1]);
	if (tmp[0] != tmp[1])
		ft_te(s, tab, 2, i);
	s->tex.width = tmp[0];
	adr = (unsigned int*)mlx_get_data_addr(ptr, &tmp[2], &tmp[3], &tmp[4]);
	s->ptrimg.ptr[s->ptrimg.i] = ptr;
	s->ptrimg.i++;
	free(tab[0]);
	free(tab);
	s->parse.tex++;
	return (adr);
}

void			ft_resolution(t_struct *s, char *line)
{
	char			**tab;
	int				i;

	i = 0;
	s->i++;
	tab = ft_split(&line[s->i], ' ');
	while (tab[i])
		i++;
	if (i != 2)
	{
		while (i >= 0)
			free(tab[i--]);
		free(tab);
		ft_errorl(s, 3, line);
	}
	ft_checkcolor(s, tab);
	s->win.x = ft_atoi((const char *)tab[0]);
	s->win.y = ft_atoi((const char *)tab[1]);
	ft_resolutionii(s, 0);
	while (i >= 0)
		free(tab[i--]);
	s->parse.res++;
	free(tab);
}

/*
**	ft_resolutionii(s, 1); for mac
*/

void			ft_read_line(t_struct *s, char *line)
{
	ft_skip_space(s, line);
	if (line[s->i] == 'R' && line[s->i + 1] == ' ')
		ft_resolution(s, &line[s->i]);
	if (line[s->i] == 'N' && line[s->i + 1] == 'O' && line[s->i + 2] == ' ')
		s->tex.n = ft_load_tex(s, &line[s->i]);
	if (line[s->i] == 'S' && line[s->i + 1] == 'O' && line[s->i + 2] == ' ')
		s->tex.s = ft_load_tex(s, &line[s->i]);
	if (line[s->i] == 'W' && line[s->i + 1] == 'E' && line[s->i + 2] == ' ')
		s->tex.w = ft_load_tex(s, &line[s->i]);
	if (line[s->i] == 'E' && line[s->i + 1] == 'A' && line[s->i + 2] == ' ')
		s->tex.e = ft_load_tex(s, &line[s->i]);
	if (line[s->i] == 'S' && line[s->i + 1] == ' ')
		s->tex.sprite = ft_load_tex(s, &line[s->i]);
	if (line[s->i] == 'F' && line[s->i + 1] == ' ')
		s->floor = ft_color(s, &line[s->i]);
	if (line[s->i] == 'C' && line[s->i + 1] == ' ')
		s->sky = ft_color(s, &line[s->i]);
	return ;
}

void			ft_parse(t_struct *s)
{
	char		*line;
	int			fd;

	if ((fd = open(s->cub, O_RDONLY)) < 0)
		ft_error(s, 8);
	while (get_next_line(fd, &line) == 1)
	{
		s->i = 0;
		if (ft_check_parsing(s) == 1)
			ft_load_map(s, line);
		else
		{
			ft_checkfirstchars(s, line);
			ft_read_line(s, line);
			free(line);
		}
	}
	free(line);
	if (ft_check_parsing(s) == -1)
		ft_error(s, 5);
	ft_get_pos(s);
	ft_check_map(s);
	if (s->parse.tex != 5 || s->parse.color != 2 || s->parse.res != 1)
		ft_error(s, 13);
	close(fd);
}
