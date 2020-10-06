/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 15:52:53 by pcoureau          #+#    #+#             */
/*   Updated: 2020/10/06 14:51:05 by paco             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

char    *ft_strjoingnl(char const *s1, char const *s2);
int     ft_strchrbn(const char *s);
char    *ft_strdcpy(const char *s);
char    *ft_strdupgnl(const char *s);
int     ft_strlengnl(char const *s);

#endif
