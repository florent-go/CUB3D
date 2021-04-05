/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgomez <fgomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 14:04:50 by fgomez            #+#    #+#             */
/*   Updated: 2021/04/01 10:40:45 by fgomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "mlx.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>

# define ROTATE_LEFT 123
# define ROTATE_RIGHT 124
# define FORWARD_W_Z 13
# define BACK_S_S 1
# define RIGHT_D_D 2
# define LEFT_A_Q 0
# define ESCAPE 53

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4000
# endif

typedef struct s_sprxy
{
	double			x;
	double			y;
}					t_sprxy;

typedef struct s_sprite
{
	int			nbspr;
	int			*order;
	double		*dist;
	double		spritex;
	double		spritey;
	double		invdet;
	double		transformx;
	double		transformy;
	int			spritescreenx;
	int			spriteheight;
	int			drawstartx;
	int			drawstarty;
	int			drawendy;
	int			drawendx;
	int			spritewidth;
	double		*zbuffer;
}					t_sprite;

typedef struct s_texture
{
	int			texdir;
	double		wallx;
	int			texx;
	int			texy;
	double		step;
	double		texpos;
}				t_texture;

typedef struct s_rayon
{
	double		posx;
	double		walldist;
	double		posy;
	double		sidedistx;
	double		sidedisty;
	double		dirx;
	double		diry;
	double		planx;
	double		plany;
	double		camera;
	double		raydirx;
	double		raydiry;
	double		deltax;
	double		deltay;
	double		movespeed;
	double		rotspeed;

	int			mapx;
	int			mapy;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			lineheight;
	int			drawstart;
	int			drawend;
	int			x;
}				t_rayon;

typedef struct s_data
{
	void		*img2;
	void		*mlx_ptr;
	void		*win;
	char		*addr2;
	int			bpp;
	int			ll;
	int			endian;
	int			width;
	int			height;
}				t_data;

typedef struct s_map
{
	int			nblignes;
	int			sizelignes;
	char		**map;
	char		depart;
	int			screenx;
	int			screeny;
	int			scrx;
	int			scry;
	int			dx;
	int			dy;
	int			count2;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		*sp;
	int			i;
	int			f;
	int			c;
	int			ro;
	int			gr;
	int			bl;

	char		forward;
	char		backward;
	char		right;
	char		left;
	char		rotate_left;
	char		rotate_right;

	t_data		texture[5];
	t_data		d;
	t_rayon		r;
	t_sprite	s;
	t_texture	t;
	t_sprxy		*sxy;
}				t_map;

char			*ft_strdupl(char *src);
int				ft_strlen(const char *str);
char			*ft_strcherche(const char *s, int c);
char			*ft_sousstr(char const *s, unsigned int start, size_t len);
char			*ft_stringjoin(char const *s1, char const *s2);
int				ft_tern(int a, int fals, int part, char **str);
char			*ft_memalloc(size_t size);
char			*verif_ret(char *str, int ret);
int				ft_strfree(char **ptr);
int				get_next_line(int fd, char **line);
int				ft_check_arg3(char *str);
int				ft_check_arg2(char *str, t_map *p);
int				ft_g_error(char *str, t_map *p);
int				main(int argc, char **argv);
void			ft_initialisation(t_map *map);
void			ft_initialisation2(t_map *p);
void			ft_initialisation3(t_map *p);
void			ft_init_sprite(t_map *p);
int				ft_murs(t_map *p);
void			ft_init_sprite2(t_map *p, int i, int j, int v);
void			ft_resolution(char **str, t_map *p);
void			parse_map(t_map *params, char **maplines);
void			ft_parse(char *fichier, t_map *map);
void			ft_map(char *str, t_map *map);
int				ft_is_map(char *str);
int				ft_copy_map(char *str, t_map *map);
void			ft_putstr(char *str);
int				ft_strlen2(char *str);
void			ft_drawminimap(t_map *p);
int				ft_atoi2(const char *str, t_map *p);
int				ft_charinstr(char *str, char c);
int				ft_depart(char c, t_map *map, int i, int j);
int				ft_mlx(t_map *params);
int				ft_run(t_map *params);
int				ft_color_column(t_map *p);
void			ft_draw_pixel(t_map *p, int x, int y, int color);
unsigned int	ft_sprite_color(t_map *p, int x, int y);
void			ft_sprite(t_map *p);
int				ft_murs_util(char *str);
int				ft_path_texture(char *str, char **texture, t_map *p, int j);
void			ft_get_texture(t_map *p);
void			ft_init_texture(t_map *p);
int				ft_keypress(int keycode, t_map *params);
int				ft_keyrelease(int keycode, t_map *params);
int				ft_move(t_map *params);

#endif
