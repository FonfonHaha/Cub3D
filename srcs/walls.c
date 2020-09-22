/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 11:54:16 by pcoureau          #+#    #+#             */
/*   Updated: 2020/03/12 18:17:07 by pcoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void    ft_hitwall(t_struct *s)
{
    while (s->wall.hit == 0)
    {
        if (s->ray.sd.x < s->ray.sd.y)
        {
            s->ray.sd.x += s->ray.dd.x;
            s->ray.pos.x += s->wall.step.x;
            s->wall.side = 0;
        } else
        {
            s->ray.sd.y += s->ray.dd.y;
            s->ray.pos.y += s->wall.step.y;
            s->wall.side = 1;
        }
        if (s->map.tab[s->ray.pos.y][s->ray.pos.x] == '1')
            s->wall.hit = 1;
    }
}

void    ft_calculsd(t_struct *s)
{
    if (s->ray.dir.x < 0)
    {
        s->wall.step.x = -1;
        s->ray.sd.x = (s->p.pos.x - s->ray.pos.x) * s->ray.dd.x;
    } else
    {
        s->wall.step.x = 1;
        s->ray.sd.x = (s->ray.pos.x + 1 - s->p.pos.x) * s->ray.dd.x;
    }
    if (s->ray.dir.y < 0)
    {
        s->wall.step.y = -1;
        s->ray.sd.y = (s->p.pos.y - s->ray.pos.y) * s->ray.dd.y;
    } else
    {
        s->wall.step.y = 1;
        s->ray.sd.y = (s->ray.pos.x + 1 - s->p.pos.y) * s->ray.dd.y;
    }
}

void    ft_rayinit(t_struct *s)
{
    s->cam = 2 * s->x / s->win.x - 1;
    s->ray.dir.x = s->p.dir.x + s->p.plane.x * s->cam;
    s->ray.dir.y = s->p.dir.y + s->p.plane.y * s->cam;
    s->ray.dd.x = s->ray.dir.y == 0 ? 0 : ((s->ray.dir.x == 0 ? 1 : fabs(1 / s->ray.dir.x)));
    s->ray.dd.y = s->ray.dir.x == 0 ? 0 : ((s->ray.dir.y == 0 ? 1 : fabs(1 / s->ray.dir.y)));
	s->ray.pos.x = (int)s->p.pos.x;
	s->ray.pos.y = (int)s->p.pos.y;
	s->wall.hit = 0;
}

void    ft_wall(t_struct *s)
{
    s->x = 0;
    while (x < s->win.x)
    {
        ft_rayinit(s);
        rt_calculsd(s);
        rt_hitwall(s);
        s->x++;
    }
}