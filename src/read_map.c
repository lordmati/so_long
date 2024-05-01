/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:46:54 by misaguir          #+#    #+#             */
/*   Updated: 2024/05/01 20:29:49 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	first_read_map(char *argv, t_game *data)
{
	int		fd;
	char	*line;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		print_error("Error file not found", data);
	line = get_next_line(fd);
	if (line == NULL)
		print_error("Map is empty", NULL);
	data->width = ft_strlen_sl(line);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line)
		{
			if (data->width != ft_strlen_sl(line))
			{
				free(line);
				print_error("Map is invalid", NULL);
			}
		}
		data->height++;
	}
	close(fd);
}

void	second_read_map(char *argv, t_game *data)
{
	int		fd;
	int		i;
	char	*line;

	i = 0;
	fd = open(argv, O_RDONLY);
	line = ft_strdup("");
	data->map = (char **)malloc(sizeof(char *) * (data->height));
	data->copy_map = (char **)malloc(sizeof(char *) * (data->height));
	if (data->map == NULL || data->copy_map == NULL)
		return ;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		if (line)
		{
			data->map[i] = ft_strdup(line);
			data->copy_map[i] = ft_strdup(line);
		}
		i++;
	}
	close(fd);
}

void	check_map(t_game *data)
{
	int	row;

	row = 1;
	check_top_and_bottom(data->map[data->height - 1], data);
	check_top_and_bottom(data->map[0], data);
	while (row < data->height - 1)
	{
		check_objects_and_wall(data->map[row], data->width, data, row);
		row++;
	}
	if (data->player != 1)
		print_error("Number players is incorrect", data);
	if (data->collect == 0)
		print_error("Number collect is incorrect", data);
	if (data->exit != 1)
		print_error("Number exit is incorrect", data);
	flood_fill(data, data->x, data->y);
}

void	flood_fill(t_game *data, int x, int y)
{
	if (data->copy_map[y][x] == '1' || data->copy_map[y][x] == 'F'
		|| x < 0 || x >= data->width || y < 0 || y >= data->height)
		return ;
	data->copy_map[y][x] = 'F';
	flood_fill(data, x - 1, y);
	flood_fill(data, x + 1, y);
	flood_fill(data, x, y - 1);
	flood_fill(data, x, y + 1);
}
