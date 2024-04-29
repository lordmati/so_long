/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:01:45 by misaguir          #+#    #+#             */
/*   Updated: 2024/04/29 20:09:15 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void init_data(t_game *data)
{
	data->height = 0;
	data->width = 0;
	data->collect = 0;
	data->player = 0;
	data->exit = 0;
	data->x = 0;
	data->y = 0;
	data->init_x = 0;
	data->init_y = 0;
	data->init_window = 0;
	return ;
}
int	main(int argc, char **argv)
{
	t_game data;

	if (argc == 2)
	{
		init_data(&data);
		check_all_map(argv[1],&data);
		init_game(&data);
	}
	else
		print_error("Error arguments no valid",NULL);
}