/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseii.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 11:54:16 by pcoureau          #+#    #+#             */
/*   Updated: 2020/10/16 14:44:26 by paco             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
			ft_error(s, 4);
		i++;
	}
}
