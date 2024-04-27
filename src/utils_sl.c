/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:41:54 by misaguir          #+#    #+#             */
/*   Updated: 2024/04/27 20:33:11 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(char *msg)
{
	ft_putstr_fd(msg, 2);
	exit(1);
}

int		ft_strlen_sl(char *str)
{
	int i;
	
	i = 0;
	while(str[i] != '\0' && str[i] != '\n')
		i++;
	return(i);
}

void	free_map(char **map)
{
	int i;

	i = 0;
	while(map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
void	printmap(t_game *data)
{
	int i = 0;
	while (i < data->height)
	{
		printf("%s",data->copy_map[i]);
		i++;
	}
}