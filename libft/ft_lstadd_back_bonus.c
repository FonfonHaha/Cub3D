/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+       */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 14:52:27 by pcoureau          #+#    #+#            */
/*   Updated: 2019/10/18 14:39:11 by pcoureau         ###   ########.fr      */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	if (!(*alst))
	{
		*alst = new;
		return ;
	}
	ft_lstlast(*alst)->next = new;
}
