/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnemili <abnemili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:58:08 by abnemili          #+#    #+#             */
/*   Updated: 2025/04/05 21:28:03 by abnemili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_walls(t_Map *map)
{
	first_row(map);
	last_row(map);
	middle_rows(map);
}

void	middle_rows(t_Map *map)
{
	int	i;

	i = 1;
	while (i < map->y - 2)
	{
		if (map->map[i][0] != '1' || map->map[i][map->x - 1] != '1')
		{
			ft_putstr("Error\nthe map not rounded by walls\n");
			free_map(map);
			exit(1);
		}
		i++;
	}
}

void	first_row(t_Map *map)
{
	int	i;

	i = 0;
	while (i < map->x)
	{
		if (map->map[0][i] != '1')
		{
			ft_putstr("Error\nthe map not rounded by walls\n");
			free_map(map);
			exit(1);
		}
		i++;
	}
}

void	last_row(t_Map *map)
{
	int	i;

	i = 0;
	while (i < map->x)
	{
		if (map->map[map->y - 1][i] != '1')
		{
			ft_putstr("Error\nthe map not rounded by walls\n");
			free_map(map);
			exit(1);
		}
		i++;
	}
}