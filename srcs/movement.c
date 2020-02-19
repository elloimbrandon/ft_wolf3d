/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfeltz <brfeltz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:39:23 by brfeltz           #+#    #+#             */
/*   Updated: 2020/02/18 22:42:07 by brfeltz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADERS/ft_wolf.h"

void	rotate_camera(t_map *map, int key)
{
	double old_dirx;
	double old_planex;
	double rot;

	rot = 0.1;
	old_dirx = map->dir_x;
	old_planex = map->plane_x;
	if (key == 2)
	{
		map->dir_x = map->dir_x * cos(-rot) - map->dir_y * sin(-rot);
		map->dir_y = old_dirx * sin(-rot) + map->dir_y * cos(-rot);
		map->plane_x = map->plane_x * cos(-rot) - map->plane_y * sin(-rot);
		map->plane_y = old_planex * sin(-rot) + map->plane_y * cos(-rot);
	}
	else
	{
		map->dir_x = map->dir_x * cos(rot) - map->dir_y * sin(rot);
		map->dir_y = old_dirx * sin(rot) + map->dir_y * cos(rot);
		map->plane_x = map->plane_x * cos(rot) - map->plane_y * sin(rot);
		map->plane_y = old_planex * sin(rot) + map->plane_y * cos(rot);
	}
	init_raycasting(map);
}

void	move_player_2(t_map *map)
{
	if (map->wmap[(int)(map->pos_x -
		map->dir_x * 0.1)][(int)map->pos_y] == 0
	|| map->wmap[(int)(map->pos_x -
			map->dir_x * 0.1)][(int)map->pos_y] == 9)
		map->pos_x -= map->dir_x * 0.1;
	if (map->wmap[(int)map->pos_y][(int)(map->pos_y -
			map->dir_y * 0.1)] == 0
	|| map->wmap[(int)map->pos_y][(int)(map->pos_y -
			map->dir_y * 0.1)] == 9)
		map->pos_y -= map->dir_y * 0.1;
}

void	move_player(t_map *map, int key)
{
	if (key == 13)
	{
		if (map->wmap[(int)(map->pos_x +
			map->dir_x * 0.1)][(int)map->pos_y] == 0 ||
			map->wmap[(int)(map->pos_x +
				map->dir_x * 0.1)][(int)map->pos_y] == 9)
			map->pos_x += map->dir_x * 0.1;
		if (map->wmap[(int)map->pos_x][(int)(map->pos_y +
			map->dir_y * 0.1)] == 0
		|| map->wmap[(int)map->pos_x][(int)(map->pos_y +
			map->dir_y * 0.1)] == 9)
			map->pos_y += map->dir_y * 0.1;
	}
	else
		move_player_2(map);
	init_raycasting(map);
}

int		ft_keymap(int key, t_map *map)
{
	if (key == 0 || key == 2)
		rotate_camera(map, key);
	if (key == 13 || key == 1)
		move_player(map, key);
	if (key == 53)
		f_close(map->mlx->mlx_ptr);
	return (0);
}
