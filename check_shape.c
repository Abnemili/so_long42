/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_shape.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnemili <abnemili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:44:08 by abnemili          #+#    #+#             */
/*   Updated: 2025/04/05 16:56:53 by abnemili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_shape(t_Map *map)
{
    int i;
    int     len;

    i = 0;
    len = 0;
    while (i < map->y)
    {
        if ((ft_strlen1(map->map[i]) != map->x || ft_strlen1(map->map[map->y \
        -1]) != map->x))
        {
            ft_putstr("Error\nthe map not rectangular\n");
			free_map(map);
			exit(1);
        }
        i++;
    }
}

