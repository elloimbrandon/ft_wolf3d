/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfeltz <brfeltz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:38:17 by brfeltz           #+#    #+#             */
/*   Updated: 2020/02/18 22:18:41 by brfeltz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADERS/ft_wolf.h"

void	draw_map(t_map *map, int x, int start, int end)
{
	if (start < end)
	{
		while (start != end)
		{
			draw_vertical_line(start, map->mlx, map->current_color, x);
			start++;
		}
	}
	else
	{
		while (start != end)
		{
			draw_vertical_line(start, map->mlx, map->current_color, x);
			start--;
		}
	}
}

void	draw_map_piece(int x, int y, t_map *map, int color)
{
	int pos_x;
	int pos_y;

	pos_x = x * 5;
	pos_y = y * 5;
	while (pos_x != (x * 5) + 5)
	{
		map->current_color = color;
		draw_map(map, pos_x, pos_y, pos_y + 5);
		pos_x++;
	}
}

void	drawplayer(t_map *map)
{
	int i;

	i = 0;
	while (i != 3)
	{
		draw_map_piece(map->pos_x + 1, map->pos_y + 1, map, RED);
		i++;
	}
}

void	draw_mini_map(t_map *map)
{
	int x;
	int y;

	x = -1;
	y = -1;
	while (++y != MAPHEIGHT)
	{
		x = -1;
		while (++x != MAPWIDTH)
		{
			if (map->wmap[x][y] >= 1)
			{
				draw_map_piece(x + 1, y + 1, map, FLOORCOLOR);
			}
		}
	}
	drawplayer(map);
}
