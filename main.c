/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnemili <abnemili@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 23:43:41 by abnemili          #+#    #+#             */
/*   Updated: 2025/04/07 22:40:19 by abnemili         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main (int ac, char **av)
{
    t_Map *map;
    
    if (ac != 2)
    {
        ft_putstr("Error\nplease check up your argument number\n");
        return (1);
    }
    map = check_map(av[1]);
    play_game(map); // in progress
}