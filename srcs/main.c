/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 11:54:16 by pcoureau          #+#    #+#             */
/*   Updated: 2020/11/02 23:11:57 by paco             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_init_iii(t_struct *s)
{
	s->map.x = 0;
	s->map.y = 0;
	s->map.sprite_nb = 0;
	s->map.sprite_countok = 0;
	s->map.tab = 0;
	s->cam = 0.0;
	s->p.pos.x = 0.0;
	s->p.pos.y = 0.0;
	s->p.dir.x = 0.0;
	s->p.dir.y = 0.0;
	s->p.plane.x = 0.0;
	s->p.plane.y = 0.0;
	s->parse.tex = 0;
	s->parse.color = 0;
	s->parse.res = 0;
	s->x = 0;
	s->keys.a = 0;
	s->keys.s = 0;
	s->keys.d = 0;
	s->keys.w = 0;
	s->keys.esc = 0;
	s->keys.left = 0;
	s->keys.right = 0;
	s->ptrimg.i = 0;
	s->sprite = NULL;
}

void	ft_init_ii(t_struct *s)
{
	s->win.ptr = 0;
	s->win.x = 0;
	s->win.y = 0;
	s->img.ptr = 0;
	s->img.adr = 0;
	s->tex.n = 0;
	s->tex.s = 0;
	s->tex.e = 0;
	s->tex.w = 0;
	s->tex.sprite = 0;
	s->tex.pos = 0.0;
	s->tex.step = 0.0;
	s->tex.x = 0;
	s->tex.y = 0;
	s->tex.width = 0;
	s->sky.r = -1;
	s->sky.g = -1;
	s->sky.b = -1;
	s->sky.color = 0;
	s->floor = s->sky;
	ft_init_iii(s);
}

void	ft_init_rc_data(t_struct *s)
{
	s->ray.pos.x = 0;
	s->ray.pos.y = 0;
	s->ray.dir = s->p.plane;
	s->ray.sd = s->p.plane;
	s->ray.dd = s->p.plane;
	s->wall.step = s->ray.pos;
	s->wall.side = 0;
	s->wall.hit = 0;
	s->wall.height = 0;
	s->wall.start = 0;
	s->wall.end = 0;
	s->wall.perp_dist = 0.0;
	s->wall.x = 0.0;
	if (!(s->wall.buf = ft_calloc(sizeof(double), s->win.x + 1)))
		ft_error(s, 1);
}

void	ft_init(char *av1, int arg)
{
	t_struct	s;
	int			tab[3];

	ft_bzero(&s, sizeof(t_struct));
	s.cub = ft_strdup(av1);
	s.mlx = mlx_init();
	ft_init_ii(&s);
	ft_parse(&s);
	ft_init_rc_data(&s);
	s.img.ptr = mlx_new_image(s.mlx, s.win.x, s.win.y);
	s.img.adr = (unsigned int*)mlx_get_data_addr(s.img.ptr,
			&tab[0], &tab[1], &tab[2]);
	if (arg == 1)
		ft_bitmap(&s);
	s.win.ptr = mlx_new_window(s.mlx, s.win.x, s.win.y, WIN_NAME);
	ft_wall(&s);
	mlx_put_image_to_window(s.mlx, s.win.ptr, s.img.ptr, 0, 0);
	mlx_hook(s.win.ptr, 2, 1L, &ft_keypress, &s);
	mlx_hook(s.win.ptr, 3, 2L, &ft_keyrelease, &s);
	mlx_hook(s.win.ptr, 17, 1L << 17, &ft_exit, &s);
	mlx_hook(s.win.ptr, 33, 1L << 17, &ft_exit, &s);
	mlx_expose_hook(s.win.ptr, &ft_display, &s);
	mlx_loop_hook(s.mlx, &ft_move, &s);
	mlx_loop(s.mlx);
	return ;
}

int		main(int ac, char **av)
{
	if (ac == 2 && ft_suffix(av[1], ".cub") == 1)
		ft_init(av[1], 0);
	else if (ac == 3 && ft_suffix(av[1], ".cub") == 1
			&& ft_strncmp(av[2], "--save", 7) == 0)
		ft_init(av[1], 1);
	else
		ft_putstr_fd("ERROR, WRONG ARGUMENTS\n", 2);
	return (1);
}
