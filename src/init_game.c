/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:42:55 by misaguir          #+#    #+#             */
/*   Updated: 2024/05/02 11:41:38 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	put_image(t_game *data, int y, int x)
{
	if (data->map[y][x] == '1')
		mlx_image_to_window(data->init_mlx,
			data->image_wall, x * 64, y * 64);
	else if (data->map[y][x] == '0')
		mlx_image_to_window(data->init_mlx,
			data->image_floor, x * 64, y * 64);
	else if (data->map[y][x] == 'E')
		mlx_image_to_window(data->init_mlx,
			data->image_exit, x * 64, y * 64);
	else if (data->map[y][x] == 'P')
		mlx_image_to_window(data->init_mlx,
			data->image_floor, x * 64, y * 64);
	else if (data->map[y][x] == 'C')
		mlx_image_to_window(data->init_mlx,
			data->image_coin, x * 64, y * 64);
}

static	void	delete_textures(t_game *data)
{
	mlx_delete_texture(data->texture_coin);
	mlx_delete_texture(data->texture_exit);
	mlx_delete_texture(data->texture_floor);
	mlx_delete_texture(data->texture_player);
	mlx_delete_texture(data->texture_wall);
}

void	load_textures(t_game *data)
{
	data->texture_coin = mlx_load_png("textures/coin.png");
	if (!data->texture_coin)
		print_error("Error load texture_coin", data);
	data->texture_exit = mlx_load_png("textures/exit.png");
	if (!data->texture_exit)
		print_error("Error load texture_exit", data);
	data->texture_floor = mlx_load_png("textures/floor.png");
	if (!data->texture_floor)
		print_error("Error load texture_floor", data);
	data->texture_player = mlx_load_png("textures/player.png");
	if (!data->texture_player)
		print_error("Error load texture_player", data);
	data->texture_wall = mlx_load_png("textures/wall.png");
	if (!data->texture_wall)
		print_error("Error load texture_wall", data);
}

void	load_image(t_game *data)
{
	data->image_coin = mlx_texture_to_image(data->init_mlx, data->texture_coin);
	if (!data->image_coin)
		print_error("Error load image_coin", data);
	data->image_exit = mlx_texture_to_image(data->init_mlx, data->texture_exit);
	if (!data->image_exit)
		print_error("Error load image_exit", data);
	data->image_floor = mlx_texture_to_image(data->init_mlx,
			data->texture_floor);
	if (!data->image_floor)
		print_error("Error load image_floor", data);
	data->image_player = mlx_texture_to_image(data->init_mlx,
			data->texture_player);
	if (!data->image_player)
		print_error("Error load image_player", data);
	data->image_wall = mlx_texture_to_image(data->init_mlx, data->texture_wall);
	if (!data->image_wall)
		print_error("Error load image_wall", data);
	delete_textures(data);
}

void	load_image_window(t_game *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while (data->map[y][x])
		{
			put_image(data, y, x);
			x++;
		}
		y++;
	}
	mlx_image_to_window(data->init_mlx,
		data->image_player, data->x * 64, data->y * 64);
}
