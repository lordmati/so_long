/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaguir <misaguir@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:01:45 by misaguir          #+#    #+#             */
/*   Updated: 2024/04/28 17:23:55 by misaguir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game data;

	if (argc == 2)
	{
		check_all_map(argv[1],&data);
		//init_game();
		return (0);
	}
	else
		print_error("Error arguments no valid",NULL);
}