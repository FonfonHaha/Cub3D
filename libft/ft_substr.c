/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 11:08:21 by pcoureau          #+#    #+#             */
/*   Updated: 2020/10/16 13:27:49 by paco             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
    int     ssize;
	size_t	i;

	i = 0;
    ssize = ft_strlen(s);
	if (!(s))
		return (NULL);
	if (!(ptr = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len && s[start] != '\0' && start < (unsigned int)ssize)
	{
		ptr[i] = s[start];
		i++;
		start++;
	}
	ptr[i] = '\0';
	return (ptr);
}
