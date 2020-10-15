/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsii.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 11:54:16 by pcoureau          #+#    #+#             */
/*   Updated: 2020/10/15 14:56:29 by paco             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		ft_exit(t_struct *s)
{
	int	i;

	i = 0;
	i++;
	s->x = i;
	while (s->map.tab[i])
		free(s->map.tab[i++]);
	free(s->cub);
	free(s->wall.buf);
	exit(0);
}

void	ft_error(t_struct *s, int err)
{
	(err == 1) ? ft_putstr_fd("Error : calloc fail\n", 2) : 0;
	(err == 2) ? ft_putstr_fd("Error : wrong map file extension\n", 2) : 0;
	(err == 3) ? ft_putstr_fd("Error : wrong resolution description\n", 2) : 0;
	(err == 4) ?
		ft_putstr_fd("Error : wrong sky or ceiling description\n", 2) : 0;
	(err == 5) ? ft_putstr_fd("Error : missing element description\n", 2) : 0;
	(err == 6) ? ft_putstr_fd("Error : wrong texture description\n", 2) : 0;
	(err == 7) ? ft_putstr_fd("Error : couldn't create bmp file\n", 2) : 0;
	(err == 8) ? ft_putstr_fd("Error : couldn't open map file\n", 2) : 0;
	(err == 9) ?
		ft_putstr_fd("Error : map contains forbidden characters\n", 2) : 0;
	(err == 10) ? ft_putstr_fd("Error : multiple starting position\n", 2) : 0;
	(err == 11) ? ft_putstr_fd("Error : map is not closed\n", 2) : 0;
	(err == 12) ?
		ft_putstr_fd("Error : Wrong texture\n", 2) : 0;
	(err == 13) ?
		ft_putstr_fd("Error : duplicated element description\n", 2) : 0;
	exit(0);
	ft_exit(s);
}

int		ft_check_parsing(t_struct *s)
{
	if ((s->win.x == 0 || s->win.y == 0 || s->tex.n == 0 || s->tex.s == 0 ||
				s->tex.w == 0 || s->tex.e == 0 || s->tex.sprite == 0 ||
				s->floor.r == -1 || s->floor.g == -1 || s->floor.b == -1 ||
				s->sky.r == -1 || s->sky.g == -1 || s->sky.b == -1))
		return (-1);
	else
		return (1);
}

void	ft_resolutionii(t_struct *s, int n)
{
	int	x;
	int	y;

	if (n)
	{
		s->win.x = (s->win.x <= 0 ? WIDTH : s->win.x);
		s->win.x = (s->win.x > WIDTH ? WIDTH : s->win.x);
		s->win.y = (s->win.y <= 0 ? HEIGHT : s->win.y);
		s->win.y = (s->win.y > HEIGHT ? HEIGHT : s->win.y);
	}
	else
	{
		mlx_get_screen_size(s->mlx, &x, &y);
		s->win.x = (s->win.x <= 0 ? x : s->win.x);
		s->win.x = (s->win.x > x ? x : s->win.x);
		s->win.y = (s->win.y <= 0 ? y : s->win.y);
		s->win.y = (s->win.y > y ? y : s->win.y);
	}
}
