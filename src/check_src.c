/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_src.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnemili <abnemili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 21:29:07 by abnemili          #+#    #+#             */
/*   Updated: 2025/04/10 23:29:15 by abnemili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_src(t_Map *map, int *p, int *e, int *c)
{
	int		x;
	int		y;
	char	current_pos;

	map->free_space_1 = 0;
	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			current_pos = map->map[y][x];
			if (current_pos == 'P')
				(*p)++;
			else if (current_pos == 'E')
				(*e)++;
			else if (current_pos == 'C')
				(*c)++;
			else if (current_pos == '0')
				map->free_space_1++;
			x++;
		}
		y++;
	}
}

void	check_srcnum(t_Map *map, int p, int e, int c)
{
	if (!p || !e || !c)
	{
		ft_putstr("Error\nInvalid map characters\n");
		free_map(map);
		exit(1);
	}
	if (p > 1 || e > 1)
	{
		ft_putstr("Error\nInvalid map characters\n");
		free_map(map);
		exit(1);
	}
	map->collect = c;
	check_valid_src(map);
}

void	check_valid_src(t_Map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->y)
	{
		x = 0;
		while (x < map->x)
		{
			if (map->map[y][x] != 'P' && map->map[y][x] != 'E'
				&& map->map[y][x] != 'C' && map->map[y][x] != '0'
				&& map->map[y][x] != '1')
			{
				ft_putstr("Error\nUnrecognized characters\n");
				free_map(map);
				exit(1);
			}
			x++;
		}
		y++;
	}
}

void	check_src(t_Map *map)
{
	int	p;
	int	e;
	int	c;

	p = 0;
	e = 0;
	c = 0;
	count_src(map, &p, &e, &c);
	check_srcnum(map, p, e, c);
}
