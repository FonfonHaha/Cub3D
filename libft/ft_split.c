/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:50:15 by pcoureau          #+#    #+#             */
/*   Updated: 2020/10/16 13:14:33 by paco             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*free_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
	return (NULL);
}

static char	**new_tab(char **tab, char *str)
{
	char	**new_tab;
	int		i;

	i = 0;
	while (tab[i])
		i++;
	if (!(new_tab = calloc(sizeof(char **), i + 2)))
		return (NULL);
	i = 0;
	while (tab[i])
	{
		new_tab[i] = tab[i];
		i++;
	}
	free(tab);
	new_tab[i] = str;
	new_tab[i + 1] = NULL;
	return (new_tab);
}

static char	*get_str(const char *s, size_t *i, char c)
{
	char	*str;
	size_t	n;

	n = 0;
	while (s[*i + n] && s[*i + n] != c)
		n++;
	if (!(str = ft_calloc(sizeof(char), n + 1)))
		return (NULL);
	n = 0;
	while (s[*i + n] && s[*i + n] != c)
	{
		str[n] = s[*i + n];
		n++;
	}
	str[n] = '\0';
	*i = *i + n;
	return (str);
}

char		**ft_split(char const *s, char c)
{
	char		**tab;
	char		*str;
	size_t		i;

	if (!s || !(tab = ft_calloc(sizeof(char **), 1)))
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			if (!(str = get_str(s, &i, c)))
				return (free_tab(tab));
			tab = new_tab(tab, str);
		}
	}
	return (tab);
}
