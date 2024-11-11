/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrabourd <mrabourd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 20:16:31 by mrabourd          #+#    #+#             */
/*   Updated: 2023/10/02 14:37:32 by mrabourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../miniRT.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		printf("One argument expected. \n");
		return (1);
	}
	parse_scene(argv[1], &data);
	init_canvas(&data);
	ft_free_all(&data);
	return (0);
}
