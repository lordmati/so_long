/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 20:09:06 by misaguir          #+#    #+#             */
/*   Updated: 2024/05/04 14:32:33 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_all_map(char *name_map, t_game *data)
{
	if (check_extension(name_map) == 0)
		print_error("Extension no valid", NULL);
	first_read_map(name_map, data);
	second_read_map(name_map, data);
	check_map(data);
	check_map_resolved(data);
	return ;
}

void	init_game(t_game *data)
{
	data->init_mlx = mlx_init(data->width * 64,
			data->height * 64, "so_long", false);
	if (!data->init_mlx)
		print_error("Open window", data);
	load_textures(data);
	load_image(data);
	load_image_window(data);
	mlx_key_hook(data->init_mlx, &key_press, data);
	mlx_loop(data->init_mlx);
	free_map(data->map, data);
	mlx_terminate(data->init_mlx);
}
