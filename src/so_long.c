/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 20:09:06 by misaguir          #+#    #+#             */
/*   Updated: 2024/04/29 19:27:02 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_all_map(char *name_map,t_game *data)
{
	if(check_extension(name_map) == 0)
		print_error("Error extension no valid",NULL);
	first_read_map(name_map,data);
	second_read_map(name_map,data);
	check_map(data);
	check_map_resolved(data);
	return ;
}
void	init_game(t_game *data)
{
	data->init_window = mlx_init(data->width * 64,data->height * 64, "so_long",false);
	if(!data->init_window)
		print_error("Error open window",data);
	load_textures_image(data);
	mlx_image_to_window(data->init_window,data->image_floor,data->x * 64,data->y * 64);
	mlx_loop(data->init_window);

	
}