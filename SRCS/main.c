/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfeltz <brfeltz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 15:39:14 by brfeltz           #+#    #+#             */
/*   Updated: 2020/02/05 23:36:43 by brfeltz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Reference (https://lodev.org/cgtutor/raycasting.html)
*/

#include "../HEADERS/ft_wolf.h"

#define swidth 640
#define sheight 480
#define mwidth 24
#define mheight 24

int		f_close(void *mlx)
{
	(void)mlx;
	exit(0);
}

int 	**worldmap(int **wmap)
{

int	smap[mwidth][mheight] = 
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

// int		main(int argc, char **argv)
int		main(void)
{
	t_map *map;
	t_mlx *mlx;
	double camerax;
	double raydirx;
	double raydiry;
	double deltadistx;
	double deltadisty;
	double sidedistx;
	double sidedisty;
	int stepx;
	int stepy;
	int mapx;
	int mapy;
	int hit;
	int side;
	int i;
	double x;
	int	**wmap;

	i = -1;
	x = -1;
	hit = 0;
	map = ft_memalloc(sizeof(t_map));
	mlx = ft_memalloc(sizeof(t_mlx));
	map->posx = 22;
	map->posy = 12;
	map->dirx = -1;
	map->diry = 0;
	map->planex = 0;
	map->planey = 0.66;
	wmap = NULL;
	mlx = mlx_init();
	wmap = worldmap(wmap);
	mlx->mlx_window = mlx_new_window(mlx, swidth, sheight, "wolf");
	mlx->mlx_image = mlx_new_image(mlx , swidth, sheight);
	mlx_hook(mlx->mlx_window, 17, 0, f_close, mlx);
	while(1)
	{
		while(++i < ++x) // does the lower half need to be in while loop?
		{
			//calculating ray postion and direction
			camerax = 2 * i / x - 1; // x-cordinate in camera space
			raydirx = map->dirx + map->planex * camerax;
			raydiry = map->diry + map->planey * camerax;
		}
		mapx = (int)map->posx; // from now until the last else is the DDA calculations to check the distance between rays and wall
		mapy = (int)map->posy;
		deltadistx = sqrt(1 + (raydiry * raydiry) / (raydirx * raydirx));
		deltadisty = sqrt(1 + (raydirx * raydirx) / (raydirx * raydiry));
		if(raydirx < 0)
		{
			stepx = -1;
			sidedistx = (map->posx - mapx) * deltadistx;
		}
		else
		{
			stepx = 1;
			sidedistx = (mapx + 1.0 - map->posx) * deltadistx;
		}
		if(raydiry < 0)
		{
			stepy = -1;
			sidedisty = (map->posy - mapy) * deltadisty;
		}
		else
		{
			stepy = 1;
			sidedisty = (mapy + 1.0 - map->posy) * deltadisty;
		}
		// preform DDA
		while (hit == 0)
		{
			// jump to next map square, or in x-direction, or in y-direction
			if (sidedistx < sidedisty)
			{
				sidedistx += deltadistx;
				mapx += stepx;
				side = 0;
			}
			else
			{
				sidedisty += deltadisty;
				mapy += stepy;
				side = 1;
			}
			// check if ray has hit a wall
			if (wmap[mapx][mapy] > 0)
				hit = 1;
		}
	}
}