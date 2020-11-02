/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseii.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 11:54:16 by pcoureau          #+#    #+#             */
/*   Updated: 2020/11/02 23:55:06 by paco             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int     ft_checkfirstchars(t_struct *s, char *line)
{
    ft_skip_space(s, line);
    if (line[s->i] == 'R' && line[s->i + 1] == ' ')
        return (1);
    if (line[s->i] == 'N' && line[s->i + 1] == 'O' && line[s->i + 2] == ' ') 
        return (1);
    if (line[s->i] == 'S' && line[s->i + 1] == 'O' && line[s->i + 2] == ' ')
        return (1);
    if (line[s->i] == 'W' && line[s->i + 1] == 'E' && line[s->i + 2] == ' ')
        return (1);
    if (line[s->i] == 'E' && line[s->i + 1] == 'A' && line[s->i + 2] == ' ')
        return (1);
    if (line[s->i] == 'S' && line[s->i + 1] == ' ')
        return (1);
    if (line[s->i] == 'F' && line[s->i + 1] == ' ')
        return (1);
    if (line[s->i] == 'C' && line[s->i + 1] == ' ')
        return (1);
    if (line[s->i] == 0)
        return (1);
    s->errorline = 1;
    return (0);
}

void	ft_checkcolor(t_struct *s, char **tab)
{
    int i;
    int y;

    i = 0;
    y = 0;
    while (tab[i])
    {
        y = 0;
        while (tab[i][y] == ' ')
            y++;
        while (ft_isdigit(tab[i][y]))
            y++;
        while (tab[i][y] == ' ')
            y++;
        if (tab[i][y])
            s->errorline = 1;
        i++;
    }
}
