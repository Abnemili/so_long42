/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnemili <abnemili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:11:09 by abnemili          #+#    #+#             */
/*   Updated: 2025/04/12 15:50:15 by abnemili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_Map	fill_map_cpy(char *av)
{
	t_Map	map;
	int		h;

	h = map_height(av);
	map.y = h;
	map.map = malloc(sizeof(char *) * (h + 1));
	if (!map.map)
		ft_fail();
	parse_map_file(&map, av);
	map.x = ft_strlen1(map.map[0]);
	map.check_c = 0;
	return (map);
}

void	starting_pose(int *x, int *y, t_Map *map)
{
	int	flag;

	flag = 0;
	*y = 0;
	while (*y < map->y)
	{
		*x = 0;
		while (*x < map->x)
		{
			if (map->map[*y][*x] == 'P')
			{
				flag++;
				break ;
			}
			(*x)++;
		}
		if (flag)
			break ;
		(*y)++;
	}
}

void	check_path(char *av, t_Map *map)
{
	t_Map	map_cpy;
	int		x;
	int		y;
	int		i;
	int		flag;

	map_cpy = fill_map_cpy(av);
	x = 0;
	y = 0;
	i = 0;
	flag = 0;
	starting_pose(&x, &y, map);
	map_cpy.check_c = 0;
	flood_file(&map_cpy, x, y, &flag);
	while (map_cpy.map[i])
		free(map_cpy.map[i++]);
	free(map_cpy.map);
	if (!flag || map_cpy.check_c != map->collect)
	{
		ft_putstr("Error\ninvalid path\n");
		free_map(map);
		exit(1);
	}
}
