/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 14:11:08 by pcoureau          #+#    #+#             */
/*   Updated: 2020/10/16 13:12:22 by paco             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	int r;
	int t;

	if (fd < 0)
		return ;
	t = 0;
	if (nb == -2147483648)
		write(fd, &"-2147483648", 11);
	else
	{
		if (nb >= 0)
			t = nb;
		else
		{
			write(fd, "-", 1);
			t = -nb;
		}
		r = t % 10;
		t = t / 10;
		if (t != 0)
			ft_putnbr_fd(t, fd);
		ft_putchar_fd(r + '0', fd);
	}
}
