/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:42:55 by misaguir          #+#    #+#             */
/*   Updated: 2024/04/29 19:26:29 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_textures_image(t_game *data)
{
	data->texture_all = mlx_load_png("textures/coin.png");
	data->image_coin = mlx_texture_to_image(data->init_window,data->texture_all);
	mlx_delete_texture(data->texture_all);
	data->texture_all = mlx_load_png("textures/exit.png");
	data->image_exit = mlx_texture_to_image(data->init_window,data->texture_all);
	mlx_delete_texture(data->texture_all);
	data->texture_all = mlx_load_png("textures/floor.png");
	data->image_floor = mlx_texture_to_image(data->init_window,data->texture_all);
	mlx_delete_texture(data->texture_all);
	data->texture_all = mlx_load_png("textures/player.png");
	data->image_player = mlx_texture_to_image(data->init_window,data->texture_all);
	mlx_delete_texture(data->texture_all);
	data->texture_all = mlx_load_png("textures/wall.png");
	data->image_wall = mlx_texture_to_image(data->init_window,data->texture_all);
	free(data->texture_all);
	return ;
}
