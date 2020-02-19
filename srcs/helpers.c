/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfeltz <brfeltz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:37:49 by brfeltz           #+#    #+#             */
/*   Updated: 2020/02/18 22:10:06 by brfeltz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADERS/ft_wolf.h"

int		f_close(void *mlx)
{
	(void)mlx;
	system("pkill afplay");
	exit(0);
}

int		curr_color_green(t_map *map)
{
	map->current_color = map->side == 0 ? GREEN : GREENSHADE;
	return (map->current_color);
}

int		curr_color_blue(t_map *map)
{
	map->current_color = map->side == 0 ? BLUE : BLUESHADE;
	return (map->current_color);
}

int		curr_color_red(t_map *map)
{
	map->current_color = map->side == 0 ? RED : REDSHADE;
	return (map->current_color);
}

void	color_picker(t_map *map)
{
	int i;

	i = map->wmap[map->map_x][map->map_y];
	if (i == 1)
		map->current_color = map->side == 0 ? PURPLE : PURPLESHADE;
	else if (i == 2)
		map->current_color = map->side == 0 ? ORANGE : ORANGESHADE;
	else if (i == 3)
		map->current_color = curr_color_green(map);
	else if (i == 4)
		map->current_color = curr_color_blue(map);
	else if (i == 5)
		map->current_color = curr_color_red(map);
	else if (i == 9)
		map->current_color = map->side == 0 ? ORANGE : ORANGESHADE;
}
