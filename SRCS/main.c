/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfeltz <brfeltz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:39:14 by brfeltz           #+#    #+#             */
/*   Updated: 2020/02/06 20:39:52 by brfeltz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Reference (https://lodev.org/cgtutor/raycasting.html)
*/

#include "../HEADERS/ft_wolf.h"



static void		ft_map_init(t_map *map)
{
	map->posx = 22;
	map->posy = 12;
	map->dirx = -1;
	map->diry = 0;
	map->planex = 0;
	map->planey = 0.66;
	// map->time = 0;
	// map->old_time = 0;
	map->camerax = 0;
	map->raydirx = 0;
	map->raydiry = 0;
	map->deltadistx = 0;
	map->deltadisty = 0;
	map->sidedistx = 0;
	map->sidedisty = 0;
	map->wallx = 0;
	map->tex_x = 0;
	map->texwidth = 0;
	map->perpwalldist = 0;
	map->perpwalldist = 0;
	map->lineheight = 0;
	map->drawstart = 0;
	map->drawend = 0;
	map->stepx = 0;
	map->stepy = 0;
	map->mapx = 0;
	map->mapy = 0;
	map->hit = 0;
	map->side = 0;
}

int		f_close(void *mlx)
{
	(void)mlx;
	exit(0);
}

int 	**worldmap(int **wmap)
{

int	smap[MWIDTH][MHEIGHT] = 
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};

wmap = (int**)smap;
return(wmap);
}

static void		ft_ray_position(t_map *map, int i)
{
	//calculating ray postion and direction
	map->camerax = 2 * i / i - 1; // x-cordinate in camera space // (double)swidth - 1;
	map->raydirx = map->dirx + map->planex * map->camerax;
	map->raydiry = map->diry + map->planey * map->camerax;
	map->mapx = (int)map->posx; // from now until the last else is the DDA calculations to check the distance between rays and wall
	map->mapy = (int)map->posy;
	map->deltadistx = sqrt(1 + (map->raydiry * map->raydiry) / (map->raydirx * map->raydirx));
	map->deltadisty = sqrt(1 + (map->raydirx * map->raydirx) / (map->raydirx * map->raydiry));

}

static void		ft_ray_direction(t_map *map)
{
	if(map->raydirx < 0)
	{
		map->stepx = -1;
		map->sidedistx = (map->posx - map->mapx) * map->deltadistx;
	}
	else
	{
		map->stepx = 1;
		map->sidedistx = (map->mapx + 1.0 - map->posx) * map->deltadistx;
	}
	if(map->raydiry < 0)
	{
		map->stepy = -1;
		map->sidedisty = (map->posy - map->mapy) * map->deltadisty;
	}
	else
	{
		map->stepy = 1;
		map->sidedisty = (map->mapy + 1.0 - map->posy) * map->deltadisty;
	}
}

static void		ft_dda_start(t_map *map, int **wmap)
{
	while (map->hit == 0)
	{
		// jump to next map square, or in x-direction, or in y-direction
		if (map->sidedistx < map->sidedisty)
		{
			map->sidedistx += map->deltadistx;
			map->mapx += map->stepx;
			map->side = 0;
		}
		else
		{
			map->sidedisty += map->deltadisty;
			map->mapy += map->stepy;
			map->side = 1;
		}
		// check if ray has hit a wall
		if (wmap[map->mapx][map->mapy] > 0)
			map->hit = 1;
	}
}

static void		ft_ray_wall_dist(t_map *map)
{
	if(map->side == 0)
		map->perpwalldist = (map->mapx - map->posx + (1 - map->stepx) / 2) / map->raydirx;
	else
		map->perpwalldist = (map->mapy - map->posy + (1 - map->stepy) / 2) / map->raydiry;
}

static void		ft_line_postition(t_map *map)
{
	map->lineheight = (int)(SHEIGHT * 2 / map->perpwalldist); // take away the * 2 to make the walls not as tall
	map->drawstart = map->lineheight - 1 / 2 + SHEIGHT / 2;
	if(map->drawstart < 0)
		map->drawstart = 0;
	map->drawend = map->lineheight / 2 + SHEIGHT / 2;
	if(map->drawend >= SHEIGHT)
		map->drawend = SHEIGHT - 1;
}

static void		ft_texture_handle(t_map *map)
{
	//int texNum = worldMap[mapX][mapY] - 1; //1 subtracted from it so that texture 0 can be used!
	if(map->side == 0)
		map->wallx = map->posy + map->perpwalldist * map->raydiry;
	else
		map->wallx = map->posy + map->perpwalldist * map->raydirx;
	map->wallx -= floor(map->wallx);
	map->tex_x = ((int) map->wallx * (double)map->texwidth);
	if(map->side == 0 && map->raydirx > 0) 
		map->tex_x = map->texwidth - map->tex_x - 1;
	if(map->side == 1 && map->raydiry < 0) // !map->raydiry
		map->tex_x = map->texwidth - map->tex_x - 1;
	
}

// int		main(int argc, char **argv)
int		main(void)
{
	t_map *map;
	t_mlx *mlx;
	int i;
	int	**wmap;

	i = -1;
	map = ft_memalloc(sizeof(t_map));
	mlx = ft_memalloc(sizeof(t_mlx));
	wmap = NULL;
	mlx = mlx_init();
	ft_map_init(map);
	wmap = worldmap(wmap); // parse function here
	mlx->mlx_window = mlx_new_window(mlx, SWIDTH, SHEIGHT, "wolf");
	mlx_hook(mlx->mlx_window, 17, 0, f_close, mlx);
	//mlx_hook(mlx->mlx_window, 17, 0, ft_keys, mlx); // for key presses
	mlx_loop(mlx);
	while(++i != SWIDTH) // while not the map width(640)
	{
		ft_ray_position(map, i);
		map->hit = 0;
		ft_ray_direction(map);
		ft_dda_start(map, wmap);
		ft_ray_wall_dist(map);
		ft_line_postition(map);
		ft_texture_handle(map);
		i++;

	}
	mlx_put_image_to_window(mlx, mlx->mlx_window, mlx->mlx_image, 0, 0);
}