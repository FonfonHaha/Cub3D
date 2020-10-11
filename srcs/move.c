/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 11:54:16 by pcoureau          #+#    #+#             */
/*   Updated: 2020/10/05 16:02:23 by paco             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_rotate(t_struct *s, double n)
{
	double	olddx;
	double	oldpx;
	double	rot;

	rot = ANGLE * n;
	olddx = s->p.dir.x;
	oldpx = s->p.plane.x;
	s->p.dir.x = s->p.dir.x * cos(rot) - s->p.dir.y * sin(rot);
	s->p.dir.y = olddx * sin(rot) + s->p.dir.y * cos(rot);
	s->p.plane.x = s->p.plane.x * cos(rot) - s->p.plane.y * sin(rot);
	s->p.plane.y = oldpx * sin(rot) + s->p.plane.y * cos(rot);
}

void	ft_movef(t_struct *s, double n)
{
	int		x;
	int		y;

	x = (int)(s->p.pos.x + n * s->p.dir.x * SPEED);
	y = (int)(s->p.pos.y + n * s->p.dir.y * SPEED);
	if (s->map.tab[(int)(s->p.pos.y)][(int)(x)] == '0')
		s->p.pos.x += n * s->p.dir.x * SPEED;
	if (s->map.tab[(int)(y)][(int)s->p.pos.x] == '0')
		s->p.pos.y += n * s->p.dir.y * SPEED;
}

void	ft_moves(t_struct *s, double n)
{
	if (s->map.tab[(int)(s->p.pos.y)]
			[(int)(s->p.pos.x + n * -s->p.dir.y * SPEED)] == '0')
		s->p.pos.x += n * -s->p.dir.y * SPEED;
	if (s->map.tab[(int)(s->p.pos.y + n * s->p.dir.x * SPEED)]
			[(int)s->p.pos.x] == '0')
		s->p.pos.y += n * s->p.dir.x * SPEED;
}

int		key_press(int key, t_struct *s)
{
	if (key == ESC)
		ft_exit(s);
	else if (key == KEY_A)
		ft_moves(s, -1);
	else if (key == KEY_S)
		ft_movef(s, -1);
	else if (key == KEY_D)
		ft_moves(s, 1);
	else if (key == KEY_W)
		ft_movef(s, 1);
	else if (key == KEY_LEFT)
		ft_rotate(s, -1);
	else if (key == KEY_RIGHT)
		ft_rotate(s, 1);
	ft_wall(s);
	mlx_put_image_to_window(s->mlx, s->win.ptr, s->img.ptr, 0, 0);
	return (1);
}
