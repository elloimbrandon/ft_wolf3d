/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfeltz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:44:06 by brfeltz           #+#    #+#             */
/*   Updated: 2020/02/11 16:44:11 by brfeltz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// // void    ft_pixel_color(t_info *info, int x, int y, int pix_color)
// void    ft_pixel_color(t_map *map, t_mlx *mlx, int  pix_color)
// {
//         void    *ptr;
// 		int		bits_per_pix;
// 		int		endian;
// 		int		size_l;
//         int             c_val;

//         if (map->tex_x < SWIDTH && map->tex_x < SHEIGHT && map->texwidth < SWIDTH)
//         {
//                 ptr = mlx_get_data_addr(mlx->mlx_image,
//                         &(bits_per_pix), &(size_l), &(endian));
//                 c_val = mlx_get_color_value(mlx, pix_color);
//                 ft_memcpy(ptr + 4 * SWIDTH * map->drawend + map->drawstart * 4, &c_val, sizeof(int));
//         }
// }

// void	ft_tex_color(t_map *map, t_mlx *mlx, int i)
// {
// 	int ft_start; //end
// 	int ft_end; //start
// 	int	pix_color;
	// int	size_l;
	// int	bits_per_pix;
	// int	endian;
// 	int	c_val;
// 	void *ptr;

// 	bits_per_pix = 0;
// 	endian = 0;
// 	pix_color = 2055;
// 	ft_start = map->drawstart;
// 	ft_end = map->drawend;
// 	while(ft_start != ft_end)
// 	{
// 		ptr = mlx_get_data_addr(mlx->mlx_image,
// 			&(bits_per_pix), &(size_l), &(endian));
// 		c_val = mlx_get_color_value(mlx, pix_color);
// 		ft_memcpy(ptr + 4 * SWIDTH * map->drawstart + i * 4, &c_val, sizeof(int));
// 		ft_start++;
// 	}
// }
