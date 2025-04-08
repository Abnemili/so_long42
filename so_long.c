/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnemili <abnemili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 20:47:08 by abnemili          #+#    #+#             */
/*   Updated: 2025/04/08 15:51:35 by abnemili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_putnbr(int n)
{
	long	nb;

	nb = (long int)n;
	if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
	}
	if (nb < 10)
		ft_putchar(nb + '0');
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

void	render_map(t_Map *map)
{
	int		i;
	int		j;
	int		x;
	int		y;
	void	*img;

	y = 0;
	i = 0;
	while (i < map->y)
	{
		x = 0;
		j = 0;
		while (j < map->x)
		{
			img = lookup_tile_image(map, i, j);
			apply_tile_texture(map, img, x, y);
			x += 64;
			j++;
		}
		y += 64;
		i++;
	}
}

int	handle_key_input(int keycode, t_Map *map)
{
	static int	count;
	int			temp;

	if (keycode == 65307)
	{
		mlx_destroy_window(map->mlx, map->win);
		free_images(map);
		mlx_destroy_display(map->mlx);
		free(map->mlx);
		free_map(map);
		exit(0);
	}
	else
	{
		temp = count;
		move_player(map, keycode, &count);
		if (temp != count)
		{
			ft_putstr("count is :");
			ft_putnbr(count);
			ft_putstr("\n");
		}
	}
	return (0);
}

int	close_window(t_Map *map)
{
	mlx_destroy_window(map->mlx, map->win);
	free_images(map);
	mlx_destroy_display(map->mlx);
	free(map->mlx);
	free_map(map);
	exit(0);
	return (0);
}

void	play_game(t_Map *map)
{
	mlx_connection(map);
	load_textures(map);
	render_map(map);
	mlx_hook(map->win, 2, 1, handle_key_input, map);
	mlx_hook(map->win, 17, 0, close_window, map);
	mlx_loop(map->mlx);
}
