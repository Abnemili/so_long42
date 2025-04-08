/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_p_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnemili <abnemili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 20:15:49 by abnemili          #+#    #+#             */
/*   Updated: 2025/04/08 15:20:20 by abnemili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_file(t_Map *map, int x, int y, int *flag)
{
	if (y < 0 || y >= map->y || x < 0 || x >= map->x || map->map[y][x] == '1')
		return ;
	if (map->map[y][x] == 'C')
		map->check_c++;
	if (map->map[y][x] == 'E')
	{
		(*flag)++;
		return ;
	}
	map->map[y][x] = '1';
	flood_file(map, x - 1, y, flag);
	flood_file(map, x + 1, y, flag);
	flood_file(map, x, y - 1, flag);
	flood_file(map, x, y + 1, flag);
}

void	ft_putchar(char c)
{
	write(0, &c, 1);
}