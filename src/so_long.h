/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:09:08 by misaguir          #+#    #+#             */
/*   Updated: 2024/04/29 20:19:28 by misaguir         ###   ########.fr       */
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
	int		init_x;
	int		init_y;
	mlx_t	*init_window;
	mlx_texture_t *texture_all;
	mlx_image_t *image_floor;
	mlx_image_t *image_wall;
	mlx_image_t *image_exit;
	mlx_image_t *image_coin;
	mlx_image_t *image_player;
}	t_game;

#define WIDTH 512
#define HEIGHT 512

int		check_extension(char *str);
void	print_error(char *msg,t_game *data);
void	first_read_map(char *argv, t_game *data);
int		ft_strlen_sl(char *str);
void	second_read_map(char *argv, t_game *data);
void	check_map(t_game *data);
void	check_top_and_bottom(char *str, t_game *data);
void	check_objects_and_wall(char *str, int large,t_game *data, int row);
void	flood_fill(t_game *data, int x, int y);
void	check_all_map(char *name_map,t_game *data);
void	check_map_resolved(t_game *data);
void	free_map(char **map,t_game *data);
void	init_game(t_game *data);
void	load_textures_image(t_game *data);
void	load_image_window(t_game *data);
/// BORRAR
void	printmap(t_game *data);

#endif