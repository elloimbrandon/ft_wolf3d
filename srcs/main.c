/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfeltz <brfeltz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:39:14 by brfeltz           #+#    #+#             */
/*   Updated: 2020/02/18 21:52:24 by brfeltz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Reference (https://lodev.org/cgtutor/raycasting.html)
*/

#include "../HEADERS/ft_wolf.h"

int		**allocate_map(t_map *map)
{
	int **maps;

	map->mh->row = -1;
	maps = ft_memalloc(sizeof(int*) * MAPWIDTH);
	while (++map->mh->row < MAPWIDTH)
		maps[map->mh->row] = ft_memalloc(sizeof(int*) * MAPWIDTH);
	map->mh->row = 0;
	map->mh->bytes_read = 0;
	return (maps);
}

void	init_raycasting(t_map *map)
{
	map->x = 0;
	while (map->x < SCREENWIDTH)
	{
		calc_ray_pos(map);
		calc_ray_dir(map);
		calc_ray_collision(map);
		calc_perpendicular_distance(map);
		calc_wall_draw(map);
		map->x += 1;
	}
	draw_mini_map(map);
	mlx_put_image_to_window(map->mlx->mlx_ptr, map->mlx->mlx_win,
		map->mlx->mlx_image, 0, 0);
}

int		main(int ac, char **av)
{
	t_map *map;

	if (ac != 2 || av[0] == NULL)
	{
		ft_printf("%sError: no map file specified..\n", KRED);
		exit(1);
	}
	map = init_map_env();
	load_map(av[1], map);
	init_raycasting(map);
	mlx_hook(map->mlx->mlx_win, 17, 0, f_close, map->mlx->mlx_ptr);
	mlx_hook(map->mlx->mlx_win, 2, 0, ft_keymap, map);
	mlx_loop(map->mlx->mlx_ptr);
	return (1);
}
