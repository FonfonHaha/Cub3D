/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilsii.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 11:54:16 by pcoureau          #+#    #+#             */
/*   Updated: 2020/11/03 00:05:06 by paco             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		ft_exit(t_struct *s)
{
	int	i;

	i = 0;
	s->x = i;
	if (s->map.tab)
	{
		while (s->map.tab[i])
			free(s->map.tab[i++]);
		free(s->map.tab);
	}
	i = s->ptrimg.i - 1;
	while (i >= 0)
		mlx_destroy_image(s->mlx, s->ptrimg.ptr[i--]);
	(s->sprite) ? free(s->sprite) : 0;
	(s->wall.buf) ? free(s->wall.buf) : 0;
	(s->img.ptr) ? mlx_destroy_image(s->mlx, s->img.ptr) : 0;
	(s->win.ptr) ? mlx_destroy_window(s->mlx, s->win.ptr) : 0;
	(s->cub) ? free(s->cub) : 0;
	(s->mlx) ? free(s->mlx) : 0;
	exit(0);
}

void	ft_error(t_struct *s, int err)
{
	if (s->errorline == 1)
	{
		err = 2;
	}
	(err == 1) ? ft_putstr_fd("ERROR ON MALLOC\n", 2) : 0;
	(err == 2) ? ft_putstr_fd("ERROR ON MAP FILE\n", 2) : 0;
	(err == 3) ? ft_putstr_fd("ERROR ON RESOLUTION\n", 2) : 0;
	(err == 4) ?
		ft_putstr_fd("ERROR ON SKY OR FLOOR DESCRIPTION\n", 2) : 0;
	(err == 5) ? ft_putstr_fd("ERROR, AN ELEMENT IS MISSING\n", 2) : 0;
	(err == 6) ? ft_putstr_fd("ERROR ON TEXTURE DESCRIPTION\n", 2) : 0;
	(err == 7) ? ft_putstr_fd("ERROR BMP FILE COULD NOT CREATE IT\n", 2) : 0;
	(err == 8) ? ft_putstr_fd("ERROR, CAN NOT OPEN MAP FILE\n", 2) : 0;
	(err == 9) ?
		ft_putstr_fd("ERROR ON MAP, CHARACTER NOT ALLOWED DETECTED\n", 2) : 0;
	(err == 10) ? ft_putstr_fd("ERROR ON MAP, USE ONLY ONE START\n", 2) : 0;
	(err == 11) ? ft_putstr_fd("ERROR ON MAP, IT IS NOT CLOSED\n", 2) : 0;
	(err == 12) ?
		ft_putstr_fd("ERROR, WRONG TEXTURE\n", 2) : 0;
	(err == 13) ?
		ft_putstr_fd("ERROR, DUPLICATED ELEMENT DESCRIPTION\n", 2) : 0;
	ft_exit(s);
}

int		ft_check_parsing(t_struct *s)
{
	if ((s->win.x == 0 || s->win.y == 0 || s->tex.n == 0 || s->tex.s == 0 ||
				s->tex.w == 0 || s->tex.e == 0 || s->tex.sprite == 0 ||
				s->floor.r == -1 || s->floor.g == -1 || s->floor.b == -1 ||
				s->sky.r == -1 || s->sky.g == -1 || s->sky.b == -1))
		return (-1);
	if (s->errorline == 1)
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
