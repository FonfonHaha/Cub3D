/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_minimize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 17:57:41 by paco              #+#    #+#             */
/*   Updated: 2020/10/15 23:30:31 by paco             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		ft_key_act_deact(t_struct *s, int k, int n)
{
	if (k == ESC)
		s->keys.esc = n;
	if (k == KEY_A)
		s->keys.a = n;
	if (k == KEY_S)
		s->keys.s = n;
	if (k == KEY_D)
		s->keys.d = n;
	if (k == KEY_W)
		s->keys.w = n;
	if (k == KEY_LEFT)
		s->keys.left = n;
	if (k == KEY_RIGHT)
		s->keys.right = n;
	return (0);
}

int		ft_display(t_struct *s)
{
	ft_wall(s);
	mlx_put_image_to_window(s->mlx, s->win.ptr, s->img.ptr, 0, 0);
	return (0);
}

int		ft_keypress(int k, void *s)
{
	ft_key_act_deact(s, k, 1);
	return (0);
}

int		ft_keyrelease(int k, void *s)
{
	ft_key_act_deact(s, k, 0);
	return (0);
}
