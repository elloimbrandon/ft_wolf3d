/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brfeltz <brfeltz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 18:39:14 by brfeltz           #+#    #+#             */
/*   Updated: 2020/02/18 22:04:44 by brfeltz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADERS/ft_wolf.h"

void	set_map_coordinates(t_map *map, char *buffer, int row_index)
{
	int i;
	int k;

	i = 0;
	k = -1;
	while (buffer[++k])
	{
		if (!ft_isdigit(buffer[k]) && ft_isalpha(buffer[k]))
		{
			ft_printf("%sError: not a valid map file..\n");
			exit(1);
		}
		if (ft_isdigit(buffer[k]) && i < MAPWIDTH)
		{
			map->wmap[row_index][i] = buffer[k] - '0';
			i++;
		}
	}
}

void	validate_map_input(int fd, t_map *map, int row_index)
{
	if (fd < 0)
	{
		ft_printf("%sError: not a valid map file..\n", KRED);
		exit(1);
	}
	if (map->mh->bytes_read < 24 || row_index > 23)
	{
		ft_printf("%sError: incorrect map dimensions..\n", KRED);
		exit(1);
	}
}

void	load_map(char *str, t_map *map)
{
	int		fd;
	char	buffer[30];
	int		row_index;

	row_index = 0;
	ft_bzero(buffer, 30);
	map->wmap = allocate_map(map);
	fd = open(str, O_RDONLY);
	while ((map->mh->bytes_read = read(fd, &buffer, 25)) &&
		row_index < MAPWIDTH)
	{
		validate_map_input(fd, map, row_index);
		set_map_coordinates(map, buffer, row_index);
		ft_bzero(buffer, 30);
		row_index++;
	}
	close(fd);
}
