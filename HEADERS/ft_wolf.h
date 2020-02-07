/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfeltz <brfeltz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:42:50 by brfeltz           #+#    #+#             */
/*   Updated: 2020/02/06 20:58:36 by brfeltz          ###   ########.fr       */
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

#define SWIDTH 800
#define SHEIGHT 800
#define MWIDTH 24
#define MHEIGHT 24

/*
** Structs
*/

typedef struct          s_mlx
{
    void    *mlx_image;
    void    *mlx_window;
    void    *mlx_ptr;

}                       t_mlx;

typedef struct          s_map
{
    double posx;
	double posy;
	double dirx;
	double diry;
	double planex;
	double planey;
	double camerax;
	double raydirx;
	double raydiry;
	double deltadistx;
	double deltadisty;
	double sidedistx;
	double sidedisty;
	double wallx;
	int	tex_x;
	int texwidth;
	int perpwalldist;
	int	lineheight;
	int	drawstart;
	int drawend;
	int stepx;
	int stepy;
	int mapx;
	int mapy;
	int hit;
	int side;
}                       t_map;




/*
** Functions
*/


#endif
