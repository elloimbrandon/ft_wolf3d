/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wolf.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfeltz <brfeltz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:42:50 by brfeltz           #+#    #+#             */
/*   Updated: 2020/02/05 19:05:06 by brfeltz          ###   ########.fr       */
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
	double time;
	double old_time;
}                       t_map;




/*
** Functions
*/


#endif
