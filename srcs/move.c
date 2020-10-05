/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 11:54:16 by pcoureau          #+#    #+#             */
/*   Updated: 2020/03/12 18:17:07 by pcoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void    ft_movef(t_struct *s, double n)
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

void    ft_moves(t_struct *s, double n)
{
    if (s->map.tab[(int)(s->p.pos.y)]
        [(int)(s->p.pos.x + n * -s->p.dir.y *SPEED)] == '0')
        s->p.pos.x += n * -s->p.dir.y * SPEED;
	if (s->map.tab[(int)(s->p.pos.y + n * s->p.dir.x * SPEED)]
			[(int)s->p.pos.x] == '0')
		s->p.pos.y += n * s->p.dir.x * SPEED;
}

int     key_press(int key, t_struct *s)
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