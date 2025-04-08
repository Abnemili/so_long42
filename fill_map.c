/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnemili <abnemili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 14:10:16 by abnemili          #+#    #+#             */
/*   Updated: 2025/04/08 15:39:27 by abnemili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_height(char *av)
{
	int		fd;
	int		h;
	char	*line;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		(ft_putstr("Error\nOpen failed\n"), exit(1));
	h = 0;
	line = get_next_line(fd);
	while (line && ++h)
		(free(line), line = get_next_line(fd));
	close(fd);
	return (h);
}

static t_Map	*init_map_height(int h)
{
	t_Map	*map;

	map = malloc(sizeof(t_Map));
	if (!map)
		ft_fail();
	map->y = h;
	map->map = malloc(sizeof(char *) * (h + 1));
	if (!map->map)
		(free(map), ft_fail());
	return (map);
}

void	parse_map_file(t_Map *map, char *av)
{
	int		fd;
	int		h;
	char	*line;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		(free_map(map), ft_putstr("Error\nOpen failed\n"), exit(1));
	h = 0;
	while (h < map->y)
	{
		line = get_next_line(fd);
		map->map[h++] = line;
	}
	line = get_next_line(fd);
	if (line)
		free(line);
	close(fd);
	map->map[h] = NULL;
}

t_Map	*fill_map(char *av)
{
	t_Map	*map;
	int		h;

	h = map_height(av);
	if (h < 1)
	{
		ft_putstr("Error\n invalide map");
		exit(1);
	}
	map = init_map_height(h);
	parse_map_file(map, av);
	map->x = ft_strlen1(map->map[0]);
	return (map);
}
