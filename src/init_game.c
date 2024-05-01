/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:42:55 by misaguir          #+#    #+#             */
/*   Updated: 2024/05/01 20:06:33 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_textures_image(t_game *data)
{
	data->texture = mlx_load_png("textures/coin.png");
	data->image_coin = mlx_texture_to_image(data->init_mlx, data->texture);
	if (!data->image_coin)
		print_error("Error load image_coin", data);
	mlx_delete_texture(data->texture);
	data->texture = mlx_load_png("textures/exit.png");
	data->image_exit = mlx_texture_to_image(data->init_mlx, data->texture);
	if (!data->image_exit)
		print_error("Error load image_exit", data);
	mlx_delete_texture(data->texture);
	data->texture = mlx_load_png("textures/floor.png");
	data->image_floor = mlx_texture_to_image(data->init_mlx, data->texture);
	if (!data->image_floor)
		print_error("Error load image_floor", data);
	mlx_delete_texture(data->texture);
	data->texture = mlx_load_png("textures/player.png");
	data->image_player = mlx_texture_to_image(data->init_mlx, data->texture);
	if (!data->image_player)
		print_error("Error load image_player", data);
	mlx_delete_texture(data->texture);
	data->texture = mlx_load_png("textures/wall.png");
	data->image_wall = mlx_texture_to_image(data->init_mlx, data->texture);
	if (!data->image_wall)
		print_error("Error load image_wall", data);
	mlx_delete_texture(data->texture);
}

void	load_image_window(t_game *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				mlx_image_to_window(data->init_mlx, data->image_wall, x * 64, y * 64);
			else if (data->map[y][x] == '0')
				mlx_image_to_window(data->init_mlx, data->image_floor, x * 64, y * 64);
			else if (data->map[y][x] == 'E')
				mlx_image_to_window(data->init_mlx, data->image_exit, x * 64, y * 64);
			else if (data->map[y][x] == 'P')
				mlx_image_to_window(data->init_mlx, data->image_floor, x * 64, y * 64);
			else if (data->map[y][x] == 'C')
				mlx_image_to_window(data->init_mlx, data->image_coin, x * 64, y * 64);
			x++;
		}
		y++;
	}
	mlx_image_to_window(data->init_mlx, data->image_player, data->x * 64, data->y * 64);
}
