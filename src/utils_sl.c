/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:41:54 by misaguir          #+#    #+#             */
/*   Updated: 2024/04/28 19:28:31 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(char *msg,t_game *data)
{
	if(data != NULL)
	{
		free_map(data->copy_map,data);
		free_map(data->map,data);
	}
	ft_putstr_fd(msg, 2);
	ft_putchar_fd('\n',2);
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

void	free_map(char **map,t_game *data)
{
	int i;

	i = 0;
	if (!map|| !*map)
		return ;
	while(i < data->height)
	{
		free(map[i]);
		i++;
	}
	free(map);
	data->copy_map = NULL;
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