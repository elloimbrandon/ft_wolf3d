/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_rays.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfeltz <brfeltz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:37:33 by brfeltz           #+#    #+#             */
/*   Updated: 2020/02/18 22:17:33 by brfeltz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADERS/ft_wolf.h"

void	calc_perpendicular_distance(t_map *map)
{
	if (map->side == 0)
		map->perp_wall_dist = (map->map_x - map->pos_x + (1 - map->step_x) / 2)
			/ map->raydir_x;
	else
		map->perp_wall_dist = (map->map_y - map->pos_y + (1 - map->step_y) / 2)
			/ map->raydir_y;
	if ((int)map->perp_wall_dist == 0)
		map->perp_wall_dist = 1;
}

void	calc_ray_collision(t_map *map)
{
	while (map->hit == 0)
	{
		if (map->sidedist_x < map->sidedist_y)
		{
			map->sidedist_x += map->deltadist_x;
			map->map_x += map->step_x;
			map->side = 0;
		}
		else
		{
			map->sidedist_y += map->deltadist_y;
			map->map_y += map->step_y;
			map->side = 1;
		}
		if (MAPWIDTH <= map->map_x || map->map_x <= 0
			|| map->map_y <= 0 || MAPHEIGHT < map->map_y)
		{
			map->hit = 1;
			break ;
		}
		if (map->wmap[map->map_x][map->map_y] > 0)
			map->hit = 1;
	}
}

void	calc_ray_dir(t_map *map)
{
	if (map->raydir_x < 0)
	{
		map->step_x = -1;
		map->sidedist_x = (map->pos_x - map->map_x) * map->deltadist_x;
	}
	else
	{
		map->step_x = 1;
		map->sidedist_x = (map->map_x + 1.0 - map->pos_x) * map->deltadist_x;
	}
	if (map->raydir_y < 0)
	{
		map->step_y = -1;
		map->sidedist_y = (map->pos_y - map->map_y) * map->deltadist_y;
	}
	else
	{
		map->step_y = 1;
		map->sidedist_y = (map->map_y + 1.0 - map->pos_y) * map->deltadist_y;
	}
}

void	calc_ray_pos(t_map *map)
{
	map->camera_x = 2 * map->x / (double)(SCREENWIDTH) - 1;
	map->raydir_x = map->dir_x + map->plane_x * map->camera_x;
	map->raydir_y = map->dir_y + map->plane_y * map->camera_x;
	map->map_x = (int)map->pos_x;
	map->map_y = (int)map->pos_y;
	map->deltadist_x = fabs(1 / map->raydir_x);
	map->deltadist_y = fabs(1 / map->raydir_y);
	map->hit = 0;
}
