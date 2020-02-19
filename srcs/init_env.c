/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfeltz <brfeltz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:39:02 by brfeltz           #+#    #+#             */
/*   Updated: 2020/02/18 22:18:14 by brfeltz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADERS/ft_wolf.h"

void	init_mlx_interface(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, SCREENWIDTH, SCREENHEIGHT,
		"Wolf3d Pnunez && Brfeltz");
	mlx->mlx_image = mlx_new_image(mlx->mlx_ptr, SCREENWIDTH, SCREENHEIGHT);
	mlx->mlx_image_ptr = mlx_get_data_addr(mlx->mlx_image, &mlx->bpp,
		&mlx->line_size, &mlx->endian);
}

t_map	*init_map_env(void)
{
	t_map *map;

	map = malloc(sizeof(t_map));
	map->mlx = malloc(sizeof(t_mlx));
	map->keys = malloc(sizeof(t_keys));
	map->mh = malloc(sizeof(t_mh));
	map->pos_x = 11;
	map->pos_y = 8.5;
	map->dir_x = -1.0;
	map->dir_y = 0.0;
	map->plane_x = 0.0;
	map->plane_y = 0.66;
	init_mlx_interface(map->mlx);
	system("afplay -v 1 music/wolf.mp3 &");
	return (map);
}
