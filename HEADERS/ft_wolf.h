/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfeltz <brfeltz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:42:50 by brfeltz           #+#    #+#             */
/*   Updated: 2020/02/18 22:39:56 by brfeltz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WOLF_H
# define FT_WOLF_H
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>

/*
** Macros
*/

# define KRED "\x1B[31m"
# define RED 0xff5050
# define REDSHADE 0xCC4040
# define ORANGE 0xffa852
# define ORANGESHADE 0xA36B35
# define GREEN 0x33cc33
# define GREENSHADE 0x218221
# define BLUE 0x33BAFB
# define BLUESHADE 0x2177A1
# define PURPLE 0xC011EB
# define PURPLESHADE 0x7B0B96
# define FLOORCOLOR 0x5D5D5D
# define SKYCOLOR 0x85CCF8

# define MAPWIDTH 24
# define MAPHEIGHT 24
# define SCREENWIDTH 1000
# define SCREENHEIGHT 1000

/*
** Structs
*/

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*mlx_image;
	void		*mlx_image_ptr;
	void		*mlx_win;
	int			line_size;
	int			bpp;
	int			endian;
}				t_mlx;

typedef	struct	s_keys
{
	int			d;
	int			a;
}				t_keys;

typedef	struct	s_mh
{
	int			col;
	int			row;
	int			bytes_read;
}				t_mh;

typedef struct	s_map
{
	t_mh		*mh;
	t_keys		*keys;
	t_mlx		*mlx;
	int			x;
	int			k;
	int			hit;
	int			side;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			**wmap;
	int			height;
	int			line_start;
	int			line_end;
	int			line_height;
	int			current_color;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		camera_x;
	double		camera_y;
	double		raydir_x;
	double		raydir_y;
	double		deltadist_x;
	double		deltadist_y;
	double		sidedist_x;
	double		sidedist_y;
	double		perp_wall_dist;
}				t_map;

/*
** Functions
*/

t_map			*init_map_env(void);
int				**allocate_map(t_map *map);
int				ft_keymap(int key, t_map *map);
int				curr_color_green(t_map *map);
int				curr_color_blue(t_map *map);
int				curr_color_red(t_map *map);
int				f_close(void *mlx);
void			init_mlx_interface(t_mlx *mlx);
void			init_raycasting(t_map *map);
void			load_map(char *str, t_map *map);
void			color_picker(t_map *map);
void			rotate_camera(t_map *map, int key);
void			move_player(t_map *map, int key);
void			move_player_2(t_map *map);
void			validate_map_input(int fd, t_map *map, int row_index);
void			set_map_coordinates(t_map *map, char *buffer, int row_index);
void			prep_vertical_line(t_map *map, int draw_start, int draw_end);
void			calc_ray_pos(t_map *map);
void			calc_ray_dir(t_map *map);
void			calc_ray_collision(t_map *map);
void			calc_wall_draw(t_map *map);
void			calc_perpendicular_distance(t_map *map);
void			drawplayer(t_map *map);
void			draw_map(t_map *map, int x, int start, int end);
void			draw_mini_map(t_map *map);
void			draw_map_piece(int x, int y, t_map *map, int color);
void			draw_assist(int start, int stop, t_map *map, int color);
void			draw_vertical_line(int draw_start, t_mlx *mlx,
				int color, int x);
void			draw_sky_and_floor(t_mlx *mlx, t_map *map);

#endif
