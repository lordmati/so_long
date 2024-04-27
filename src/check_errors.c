/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:40:57 by misaguir          #+#    #+#             */
/*   Updated: 2024/04/27 21:07:33 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_extension(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	if(str[i] == '\0' && str[i - 1] == 'r' && str[i - 2] == 'e'
		&& str[i - 3] == 'b' && str[i - 4] == '.')
		return (1);
	return(0);
}

void	check_top_and_bottom(char *str)
{
	int i;

	i = 0;
	while(str[i] == '1')
		i++;
	if(str[i] == '\0' || str[i] == '\n')
		return ;
	else
		print_error("Map is invalid");
}

void	check_objects_and_wall(char *str, int large,t_game *data, int row)
{
	int i;

	i = 0;
	if(str[i] != '1' || str[large - 1] != '1')
		print_error("Map is invalid");
	while(i < large - 1)
	{
		if(str[i] != '1' && str[i] != '0' && str[i] != 'C'
			&& str[i] != 'P' && str[i] != 'E' && str[i] != '\n'
			&& str[i] != '\0')
			print_error("Map is invalid");
		if(str[i] == 'C')
			data->collect++;
		else if (str[i] == 'P')
		{
			data->player++;
			data->x = i;
			data->y = row;
		}
		else if (str[i] == 'E')
			data->exit++;
		i++;
	}
}
void	check_map_resolved(t_game *data)
{
	int	i;
	int j;

	i= 0;
	while(i < data->height - 1)
	{
		j = 0;
		while (data->copy_map[i][j])
		{
			if (data->copy_map[i][j] != 'F' && data->copy_map[i][j] != '0'
				&& data->copy_map[i][j] != '1' && data->copy_map[i][j] != '\0'
				&& data->copy_map[i][j] != '\n')
				print_error("Map is not resolved");
			j++;
		}
		i++;
	}
}
