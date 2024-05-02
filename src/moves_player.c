/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 13:15:10 by misaguir          #+#    #+#             */
/*   Updated: 2024/05/02 11:14:10 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_press(mlx_key_data_t key, void *data)
{
	t_game	*aux;

	aux = (t_game *)data;
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
	{
		free_map(aux->map, data);
		mlx_close_window(aux->init_mlx);
	}
	if (key.key == MLX_KEY_UP && key.action == MLX_PRESS)
		move_is_correct(aux, aux->y - 1, aux->x, 1);
	if (key.key == MLX_KEY_DOWN && key.action == MLX_PRESS)
		move_is_correct(aux, aux->y + 1, aux->x, 2);
	if (key.key == MLX_KEY_LEFT && key.action == MLX_PRESS)
		move_is_correct(aux, aux->y, aux->x - 1, 3);
	if (key.key == MLX_KEY_RIGHT && key.action == MLX_PRESS)
		move_is_correct(aux, aux->y, aux->x + 1, 4);
}

void	move_is_correct(t_game *data, int pos_y, int pos_x, int dir)
{
	if (data->map[pos_y][pos_x] != '1')
	{
		if (data->map[pos_y][pos_x] == 'C')
		{
			data->collect--;
			data->map[pos_y][pos_x] = '0';
			if (!mlx_image_to_window(data->init_mlx,
					data->image_floor, pos_x * 64, pos_y * 64))
				print_error("Error load floor", data);
		}
		move_player(data, dir);
		reload_player(data);
		if (data->map[pos_y][pos_x] == 'E' && data->collect == 0)
		{
			mlx_close_window(data->init_mlx);
			free_map(data->map, data);
			ft_printf("Finish game\n");
		}
	}
}

void	move_player(t_game *data, int dir)
{
	if (dir == 1)
	{
		data->y--;
		(data->image_player)->instances[0].y -= STEP;
	}
	else if (dir == 2)
	{
		data->y++;
		(data->image_player)->instances[0].y += STEP;
	}
	else if (dir == 3)
	{
		data->x--;
		(data->image_player)->instances[0].x -= STEP;
	}
	else if (dir == 4)
	{
		data->x++;
		(data->image_player)->instances[0].x += STEP;
	}
	data->move++;
	ft_printf("Moves: %d\n", data->move);
}

void	reload_player(t_game *data)
{
	mlx_delete_image(data->init_mlx, data->image_player);
	data->texture_player = mlx_load_png("textures/player.png");
	data->image_player = mlx_texture_to_image(data->init_mlx,
			data->texture_player);
	mlx_delete_texture(data->texture_player);
	if (!data->image_player)
		print_error("Error load image_player", data);
	mlx_image_to_window(data->init_mlx,
		data->image_player, data->x * 64, data->y * 64);
}
