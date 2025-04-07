/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnemili <abnemili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:51:17 by abnemili          #+#    #+#             */
/*   Updated: 2025/04/07 23:38:35 by abnemili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void apply_tile_texture(t_Map *map, void *img, int x, int y)
{
	if (!img)
	{
		ft_putstr("Error: Image loading failed\n");
		free_images(map);
		free_map(map);
		exit(1);
	}
	if (mlx_put_image_to_window(map->mlx, map->win, img, x, y) == -1)
	{
		ft_putstr("Error: Failed to put image to window\n");
		free_images(map);
		free_map(map);
		exit(1);
	}
}
void *lookup_tile_image(t_Map *map, int i, int j)
{
	char	current;
	void	*img;

	current = map->map[i][j];
	img = NULL;
	if (current == '1')
		img = map->wall;
	else if (current == '0')
		img = map->free_space;
	else if (current == 'C')
		img = map->collection;
	else if (current == 'P')
	{
		map->player_p[0] = i;
		map->player_p[1] = j;
		img = map->player;
	}
	else if (current == 'E')
		img = map->exit;
	return (img);
}

void	load_textures(t_Map *map)
{
	int	img_width;
	int	img_height;

	map->exit = mlx_xpm_file_to_image(map->mlx, "exit0.xpm", &img_width,
			&img_height);
	map->free_space = mlx_xpm_file_to_image(map->mlx, "free_space.xpm",
			&img_width, &img_height);
	map->player = mlx_xpm_file_to_image(map->mlx, "0.xpm", &img_width,
			&img_height);
	map->collection = mlx_xpm_file_to_image(map->mlx, "collect_1.xpm",
			&img_width, &img_height);
	map->wall = mlx_xpm_file_to_image(map->mlx, "wall_1.xpm", &img_width,
			&img_height);
	if (!map->exit || !map->free_space || !map->player || !map->collection
		|| !map->wall)
	{
		ft_putstr("Error: Failed to load one or more images\n");
		handle_key_input(65307, map);
		exit(1);
	}
}
void	mlx_connection(t_Map *map)
{
	map->mlx = mlx_init();
	if (!map->mlx)
	{
		ft_putstr("Error\nmlx connection fail\n");
		free_map(map);
		exit(1);
	}
	map->win = mlx_new_window(map->mlx, map->x * 64, map->y * 64, "SO_LONG");
	if (!map->win)
	{
		ft_putstr("Error\nmlx window fail\n");
		mlx_destroy_display(map->mlx);
		free(map->mlx);
		free_map(map);
		exit(1);
	}
}
