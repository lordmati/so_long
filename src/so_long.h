/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:09:08 by misaguir          #+#    #+#             */
/*   Updated: 2024/04/27 21:16:46 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../MLX42/include/MLX42/MLX42.h"
#include "../Libft/libft.h"

typedef struct s_game
{
	int		height;
	int		width;
	int		collect;
	int		player;
	int		exit;
	char	**map;
	char	**copy_map;
	int		x;
	int		y;
}	t_game;

#define WIDTH 512
#define HEIGHT 512

int		check_extension(char *str);
void	print_error(char *msg);
void	first_read_map(char *argv, t_game *data);
int		ft_strlen_sl(char *str);
void	second_read_map(char *argv, t_game *data);
void	check_map(t_game *data);
void	check_top_and_bottom(char *str);
void	check_objects_and_wall(char *str, int large,t_game *data, int row);
void	flood_fill(t_game *data, int x, int y);
void	check_all(char *name_map,t_game *data);
void	check_map_resolved(t_game *data);
/// BORRAR
void	printmap(t_game *data);

#endif