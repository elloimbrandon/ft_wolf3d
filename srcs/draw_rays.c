/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfeltz <brfeltz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:38:36 by brfeltz           #+#    #+#             */
/*   Updated: 2020/02/18 22:17:48 by brfeltz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADERS/ft_wolf.h"

void	draw_vertical_line(int draw_start, t_mlx *mlx, int color, int x)
{
	int hex;

	if (x < 0)
		x = 0;
	if (draw_start < 0)
		draw_start = 0;
	if (x < SCREENWIDTH && draw_start < SCREENHEIGHT)
	{
		hex = mlx_get_color_value(mlx->mlx_ptr, color);
		ft_memcpy(mlx->mlx_image_ptr + 4 * SCREENWIDTH * draw_start + x * 4,
			&hex, sizeof(int));
	}
}

void	draw_assist(int start, int stop, t_map *map, int color)
{
	int x;

	x = map->x;
	while (start != stop)
	{
		draw_vertical_line(start, map->mlx, color, x);
		map->k == 1 ? start++ : start--;
	}
}

void	prep_vertical_line(t_map *map, int draw_start, int draw_end)
{
	if (draw_start < draw_end)
	{
		map->k = 1;
		draw_assist(0, draw_start, map, SKYCOLOR);
		draw_assist(draw_start, draw_end, map, map->current_color);
		draw_assist(draw_end, SCREENHEIGHT, map, FLOORCOLOR);
	}
	else
	{
		map->k = 0;
		draw_assist(0, draw_start, map, FLOORCOLOR);
		draw_assist(draw_start, draw_end, map, map->current_color);
		draw_assist(draw_end, SCREENHEIGHT, map, SKYCOLOR);
	}
}

void	calc_wall_draw(t_map *map)
{
	int draw_start;
	int draw_end;

	map->line_height = (int)(SCREENHEIGHT / map->perp_wall_dist);
	draw_start = -map->line_height / 2 + SCREENHEIGHT / 2;
	if (draw_start < 0)
		draw_start = 0;
	draw_end = map->line_height / 2 + SCREENHEIGHT / 2;
	if (draw_end >= SCREENHEIGHT)
		draw_end = SCREENHEIGHT - 1;
	color_picker(map);
	prep_vertical_line(map, draw_start, draw_end);
}
