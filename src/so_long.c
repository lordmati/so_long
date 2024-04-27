/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 20:09:06 by misaguir          #+#    #+#             */
/*   Updated: 2024/04/27 20:59:13 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_all(char *name_map,t_game *data)
{
	if(check_extension(name_map) == 0)
		print_error("Error extension no valid");
	first_read_map(name_map,data);
	second_read_map(name_map,data);
	check_map(data);
	check_map_resolved(data);
}