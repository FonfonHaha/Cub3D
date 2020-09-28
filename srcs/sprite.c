/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 11:54:16 by pcoureau          #+#    #+#             */
/*   Updated: 2020/03/12 18:17:07 by pcoureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void    ft_spritepos(t_struct *s)
{
    int i;

    i = 0;
    while (i < s->map.sprite_nb)
    {
        s->y = 0;
        while (s->map.tab[s->y])
        {
            s->x = 0;
            while (s->map.tab[s->y][s->x])
            {
                if (s->map.tab[s->y][s->x] == '2')
                {
                    s->sprite[i].pos.x = s->x + 0.5;
                    s->sprite[i].pos.x = s->y + 0.5;
                    i++;
                }
                s->x++;
            }
            s->y++;
        }
    }
}

void    ft_countsprite(t_struct *s)
{
    s->y = 0;
    while (s->map.tab[s->y])
    {
        s->x = 0;
        while (s->map.tab[s->y][s->x])
        {
            if (s->map.tab[s->y][s->x] == '2')
                s->map.sprite_nb++;
            s->x++;
        }
        s->y++;
    }
}

void    ft_sprite(t_struct *s)
{
    if (s->map.sprite_nb == 0)
    {
        ft_countsprite(s);
        if (!(s->sprite = malloc(sizeof(t_sprite) * s->map.sprite_nb)))
            ft_error(s, 1);
    }
    ft_spritepos(s);

}