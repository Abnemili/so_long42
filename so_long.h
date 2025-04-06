/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnemili <abnemili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 23:09:25 by abnemili          #+#    #+#             */
/*   Updated: 2025/04/06 22:44:08 by abnemili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H


# include <fcntl.h>
# include "get_line/get_next_line.h"
//# include <mlx.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct map
{
	void	*mlx;
	void	*win;
	int		y;
	int		x;
	int		check_c;
	int		collect;
	char	**map;
	int		free_space_1;
	int		player_p[2];
	void	*player;
	void	*wall;
	void	*free_space;
	void	*collection;
	void	*exit;
}			t_Map;

t_Map *check_map(char *av);
void check_ext(char *name);
static t_Map *fill_map(char *av);
int ft_strlen(char *name);
void ft_putstr(char *error_mag);
int	ft_strlen1(char *str);
static t_Map *init_map_height(int h);
void ft_fail(void);
void  parse_map_file(t_Map *map, char *av);
void check_shape(t_Map *map);
void	first_row(t_Map *map);
void	last_row(t_Map *map);
void	middle_rows(t_Map *map);
void	check_walls(t_Map *map);
void check_src(t_Map *map);
void	check_vsrc(t_Map *map);
void	check_srcnum(t_Map *map, int p, int e, int c);
void count_src(t_Map *map, int *p, int *e, int *c);
int ft_strncmp(const char *s1, const char *s2, size_t n);
void check_path(char *av, t_Map *map);
static int map_height(char *av);
void flood_file(t_Map *map, int x, int y, int *flag);




#endif