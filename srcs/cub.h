/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcoureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 11:51:38 by pcoureau          #+#    #+#             */
/*   Updated: 2020/10/15 18:21:28 by paco             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../libft/libft.h"

#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

/*
**	keys mac**
** #define ESC 53
** #define KEY_W 13
** #define KEY_A 0
** #define KEY_S 1
** #define KEY_D 2
** #define KEY_UP 126
** #define KEY_DOWN 125
** #define KEY_LEFT 123
** #define KEY_RIGHT 124
*/

/*
**	keys linux**
*/
#define ESC 65307
#define KEY_W 119
#define KEY_A 97
#define KEY_S 115
#define KEY_D 100
#define KEY_UP 65362
#define KEY_DOWN 65364
#define KEY_LEFT 65361
#define KEY_RIGHT 65363

/*
** keys pre-setted values mapping LibX Functions
*/
#define KEY_PRESS 2
#define KEY_RELEASE 3
#define KEY_PRESS_MASK (1L<<0)
#define KEY_RELEASE_MASK (1L<<1)

/*
**	colors
*/
#define WHITE 0x00FFFFFF
#define BLACK 0x00000000
#define RED 0x00FF0000
#define BLUE 0x000000FF
#define YELLOW 0x00FFFF00
#define PINK 9961608

/*
** windows
*/
#define WIDTH 1280
#define HEIGHT 680
#define WIN_NAME "Cub3D"
#define BPP 4

/*
** moves settings
*/
#define SPEED 0.2
#define ANGLE 0.1
#define FOV 0.7

typedef struct		s_xy
{
	int				x;
	int				y;
}					t_int_xy;

typedef struct		s_double_xy
{
	double			x;
	double			y;
}					t_double_xy;

typedef struct		s_win
{
	void			*ptr;
	int				x;
	int				y;
}					t_win;

typedef struct		s_img
{
	void			*ptr;
	unsigned int	*adr;
}					t_img;

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
	unsigned int	*color;
}					t_color;

/*
** pos = where to start drawing texture
** step = ratio to increase or decrease texture bloc size
** x, y = coordinate in the texture
** width = texture bloc width
*/
typedef struct		s_tex
{
	unsigned int	*n;
	unsigned int	*s;
	unsigned int	*w;
	unsigned int	*e;
	unsigned int	*sprite;
	double			pos;
	double			step;
	int				x;
	int				y;
	int				width;
}					t_tex;

typedef struct		s_map
{
	char			**tab;
	int				h;
	int				x;
	int				y;
	int				sprite_nb;

}					t_map;

/*
** pos = ray position
** dir = ray direction
** sd = side_dist, dist from player to the next map square until hitting a wall
** dd = delta_dist, dist from the ray.pos to the next map square
*/
typedef struct		s_ray
{
	t_int_xy		pos;
	t_double_xy		dir;
	t_double_xy		sd;
	t_double_xy		dd;
}					t_ray;

/*
** start = when to start drawing the sprite on the y coordinate
** end = when to stop drawing the sprite on the y coordinate
** delta = relative x and y coordinate from the player
*/
typedef struct		s_sprite
{
	int				height;
	int				width;
	int				screen;
	double			dist;
	t_int_xy		start;
	t_int_xy		end;
	t_double_xy		pos;
	t_double_xy		delta;
	t_double_xy		depth;
}					t_sprite;

/*
** step = variable to iterate every square of the map, step is negative
**	if ray_dir < 0, so also tells us if the wall hit
**	is NSEW combined with the side value
** side = which side of the wall is hitten (x or y coordinate)
**	to know what texture to select
** hit = if 1, the wall is hit, so quit the loop
** height = height of the wall, calculated from the distance
** start = when to start drawing the wall on the y coordinate
** end = when to stop drawing the wall on the y coordinate
** perp_dist = perpendicular distance of the wall from the player plane
** x = x coordinate of the hitten wall, in order to know the x coordinate
**	of the texture to pick
** buf = buffer to keep wall distances in order to sorte sprite and
**	not display sprites behind walls (very important)
*/
typedef	struct		s_wall
{
	t_int_xy		step;
	int				side;
	int				hit;
	int				height;
	int				start;
	int				end;
	double			perp_dist;
	double			x;
	double			*buf;
}					t_wall;

/*
** pos = player position
** dir = direction of the player
** plane = camera plane, wich is always perpendicular to player dir
*/
typedef struct		s_player
{
	t_double_xy		pos;
	t_double_xy		dir;
	t_double_xy		plane;
}					t_player;

typedef struct		s_parsing
{
	int				res;
	int				tex;
	int				color;
}					t_parsing;

/*
** cam = x cam coordinate, -1 = left, 0 = center, 1 = right
** color = the color of the pixel
** cub = map file name
*/
typedef struct		s_struct
{
	void			*mlx;
	t_parsing		parse;
	t_win			win;
	t_img			img;
	t_color			sky;
	t_color			floor;
	t_tex			tex;
	t_map			map;
	t_player		p;
	t_ray			ray;
	t_wall			wall;
	t_sprite		*sprite;
	double			cam;
	unsigned int	color;
	char			*cub;
	int				i;
	int				x;
	int				y;
}					t_struct;

/*
** main.c
*/
void				ft_init(char *av1, int arg);
void				ft_init_ii(t_struct *s);
void				ft_init_iii(t_struct *s);
void				ft_init_raycasting_data(t_struct *s);

/*
** key_minimize.c
*/
int                 ft_minimize(t_struct *s);



/*
** parse.c
*/
void				ft_parse(t_struct	*s);
void				ft_read_line(t_struct *s, char	*tmp);
void				ft_resolution(t_struct *s, char	*tmp);
t_color				ft_color(t_struct *s, char	*tmp);
unsigned int		*ft_load_tex(t_struct *s, char *tmp);

/*
** parse_map.c
*/
void				ft_get_pos(t_struct *s);
void				ft_load_map(t_struct *s, char *line);
void				ft_check_map_char(t_struct *s, int x, int y);
int					ft_check_map_borders(t_struct *s, int x, int y, char **map);
void				ft_check_map(t_struct *s);

/*
** utils.c
*/
int					ft_is_space(char c);
void				ft_skip_space(t_struct *s, char *line);
int					ft_is_charset(char c, char *set);
int					ft_suffix(char *file_name, char *suffix);
char				**ft_new_tab(t_struct *s, char **tab, char *str);

/*
** utilsii.c
*/
int					ft_exit(t_struct *s);
void				ft_error(t_struct *s, int err);
int					ft_check_parsing(t_struct *s);
void				ft_resolutionii(t_struct *s, int n);

/*
** print.c
*/
void				ft_print_arg(t_struct *s);
void				print_map(t_struct *s);
void				print_sprite(t_struct *s);

/*
** walls.c
*/
void				ft_wall(t_struct *s);
void				ft_ray_init(t_struct *s);
void				ft_calculsd(t_struct *s);
void				ft_hitwall(t_struct *s);
void				ft_wallsize(t_struct *s);

/*
** wallsii.c
*/
void				ft_walltex(t_struct *s);
void				ft_drawwall(t_struct *s);
void				ft_pixel(t_struct *s);

/*
** move.c
*/
int					key_press(int key, t_struct *s);
void				ft_move_forward(t_struct *s, double sign);
void				ft_move_side(t_struct *s, double sign);
void				ft_rotate(t_struct *s, double sign);
void				ft_event(t_struct *s);

/*
** sprite.c
*/
void				ft_sprite(t_struct *s);
void				ft_countsprite(t_struct *s);
void				ft_spritepos(t_struct *s);
void				ft_spritedis(t_struct *s);
void				ft_spritetri(t_struct *s);

/*
** spriteii.c
*/
void				ft_spritetrans(t_struct *s);
void				ft_spritesize(t_struct *s);
void				ft_drawsprite(t_struct *s);

/*
** bitmap.c
*/
void				ft_bitmap(t_struct *s);
unsigned char		*ft_bmp_file_header(t_struct *s);
unsigned char		*ft_bmp_dib_header(t_struct *s);
unsigned char		*ft_bmp_pixel_array(t_struct *s);
void				ft_set_int_to_char(unsigned char *start, int value);
