/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 11:54:16 by pcoureau          #+#    #+#             */
/*   Updated: 2020/11/02 22:38:17 by paco             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_rotate(t_struct *s, double n)
{
	double	olddx;
	double	oldpx;
	double	rot;

	rot = 0.2 * n;
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

int		ft_move(t_struct *s)
{
	if (s->keys.esc)
		ft_exit(s);
	if (s->keys.w)
		ft_movef(s, 0.2);
	if (s->keys.s)
		ft_movef(s, -0.2);
	if (s->keys.a)
		ft_moves(s, -0.2);
	if (s->keys.d)
		ft_moves(s, 0.2);
	if (s->keys.left)
		ft_rotate(s, -0.2);
	if (s->keys.right)
		ft_rotate(s, 0.2);
    /*
	if (s->keys.w || s->keys.s || s->keys.a || s->keys.d
			|| s->keys.left || s->keys.right)
		ft_display(s);
        */
    ft_display(s);
	return (0);
}
