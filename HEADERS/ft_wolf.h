/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfeltz <brfeltz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:42:50 by brfeltz           #+#    #+#             */
/*   Updated: 2020/02/11 17:58:04 by brfeltz          ###   ########.fr       */
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

#define SWIDTH 640
#define SHEIGHT 480
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
	void	*mlx_image_ptr;

}                       t_mlx;

typedef struct          s_map
{
	// int **wmap;
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
	double perpwalldist;
	double wallx;
	double step;
	int	tex_x;
	int texwidth;
	int texheight; // added
	int	lineheight;
	int	drawstart;
	int drawend;
	int	line_buf;
	int stepx;
	int stepy;
	int mapx;
	int mapy;
	int hit;
	int side;
	int	size_l;// added 
	int	bits_per_pix; // added
	int	endian; // added
}                       t_map;




/*
** Functions
*/


#endif
