/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 11:54:16 by pcoureau          #+#    #+#             */
/*   Updated: 2020/10/06 13:59:30 by paco             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_spritetri(t_struct *s)
{
	int			i;
	int			j;
	t_sprite	tmp;

	i = 0;
	while (i < s->map.sprite_nb - 1)
	{
		j = i + 1;
		while (j < s->map.sprite_nb)
		{
			if (s->sprite[i].dist < s->sprite[j].dist)
			{
				tmp = s->sprite[i];
				s->sprite[i] = s->sprite[j];
				s->sprite[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

void	ft_spritedist(t_struct *s)
{
	int i;

	i = 0;
	while (i < s->map.sprite_nb)
	{
		s->sprite[i].dist = hypot(s->p.pos.x - s->sprite[i].pos.x,
				s->p.pos.y - s->sprite[i].pos.y);
		i++;
	}
}

void	ft_spritepos(t_struct *s)
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
					s->sprite[i].pos.y = s->y + 0.5;
					i++;
				}
				s->x++;
			}
			s->y++;
		}
	}
}

void	ft_countsprite(t_struct *s)
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
	s->map.sprite_countok = 1;
}

void	ft_sprite(t_struct *s)
{
	if (s->map.sprite_countok == 0)
	{
		ft_countsprite(s);
		if (s->map.sprite_nb != 0)
		{
			if (!(s->sprite = malloc(sizeof(t_sprite) * s->map.sprite_nb)))
				ft_error(s, 1);
		}
	}
	ft_spritepos(s);
	ft_spritedist(s);
	ft_spritetri(s);
	s->i = 0;
	while (s->i < s->map.sprite_nb)
	{
		ft_spritetrans(s);
		ft_spritesize(s);
		ft_drawsprite(s);
		s->i++;
	}
}
