/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wallsii.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 11:54:16 by pcoureau          #+#    #+#             */
/*   Updated: 2020/03/12 18:17:07 by pcoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void    ft_pixel(t_struct *s)
{
    int p;

    p = s->tex.width * s->tex.y + s->tex.x;
    if (s->wall.side == 0)
    {
        if (s->wall.step.x < 0)
            s->img.adr[s->x + s->win.x * s->y] = s->tex.w[p];
        else
            s->img.adr[s->x + s->win.x * s->y] = s->tex.e[p];
    }
    else
    {
        if (s->wall.step.y < 0)
            s->img.adr[s->x + s->win.x * s->y] = s->tex.n[p];
        else
            s->img.adr[s->x + s->win.x * s->y] = s->tex.s[p];
    }
}

void    ft_drawwall(t_struct *s)
{
    s->color = s->sky.r * pow(256, 2) + s->sky.g * 256 + s->sky.b;
    s->y = 0;
    while (s->y < s->wall.start)
        s->img.adr[s->x + s->win.x * s->y++] = s->color;
    while (s->y >= s->wall.start && s->y <= s->wall.end)
    {
        s->tex.y = (int)s->tex.pos;
        s->tex.pos += s->tex.step;
        ft_pixel(s);
        s->y++;
    }
}

void    ft_walltex(t_struct *s)
{
    s->tex.x = (int)(s->wall.x * s->tex.width);
    if ((s->Wall.side == 0 && s->ray.dir.x > 0) ||
        (s->wall.side == 1 && s->ray.dit.y < 0))
        s->tex.x = s->tex.width - s->tex.x - 1;
    s->tex.step = (double)s->tex.width / s->wall.height;
    s->tex.pos = (s->wall.start - s->win.y / 2 + s->wall.height / 2) * s->tex.step;
}