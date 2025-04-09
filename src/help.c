/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnemili <abnemili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 22:56:11 by abnemili          #+#    #+#             */
/*   Updated: 2025/04/09 18:29:06 by abnemili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_images(t_Map *map)
{
	if (map->exit)
		mlx_destroy_image(map->mlx, map->exit);
	if (map->floor)
		mlx_destroy_image(map->mlx, map->floor);
	if (map->player)
		mlx_destroy_image(map->mlx, map->player);
	if (map->collection)
		mlx_destroy_image(map->mlx, map->collection);
	if (map->wall)
		mlx_destroy_image(map->mlx, map->wall);
}

static void	update_player_position(t_Map *map, int dx, int dy, int *count)
{
	mlx_put_image_to_window(map->mlx, map->win, map->floor,
		map->player_p[1] * 32, map->player_p[0] * 32);
	map->player_p[1] += dx;
	map->player_p[0] += dy;
	(*count)++;
	mlx_put_image_to_window(map->mlx, map->win, map->player, map->player_p[1]
		* 32, map->player_p[0] * 32);
}

static int	is_valid_move(t_Map *map, int dx, int dy, int collected)
{
	const int	new_x = map->player_p[1] + dx;
	const int	new_y = map->player_p[0] + dy;

	if (new_x < 0 || new_x >= map->x || new_y < 0 || new_y >= map->y)
		return (0);
	if (map->map[new_y][new_x] == '1')
		return (0);
	if (map->map[new_y][new_x] == 'E' && collected != map->collect)
		return (0);
	return (1);
}

static void	handle_movement(t_Map *map, int keycode, int *count, int *collected)
{
	int	dx;
	int	dy;

	dx = 0;
	dy = 0;
	if (keycode == 65363 || keycode == 'd' || keycode == 'D')
		dx = 1;
	else if (keycode == 65361 || keycode == 'a' || keycode == 'A')
		dx = -1;
	else if (keycode == 65364 || keycode == 's' || keycode == 'S')
		dy = 1;
	else if (keycode == 65362 || keycode == 'w' || keycode == 'W')
		dy = -1;
	if (dx || dy)
	{
		if (is_valid_move(map, dx, dy, *collected))
			update_player_position(map, dx, dy, count);
	}
}

void	move_player(t_Map *map, int keycode, int *count)
{
	static int	c;

	handle_movement(map, keycode, count, &c);
	if (map->map[map->player_p[0]][map->player_p[1]] == 'C')
	{
		c++;
		map->map[map->player_p[0]][map->player_p[1]] = '0';
	}
	if (map->map[map->player_p[0]][map->player_p[1]] == 'E'
		&& c == map->collect)
	{
		ft_putstr("You win!\n");
		handle_key_input(65307, map);
	}
}
