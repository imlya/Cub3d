/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:49:55 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/17 17:16:00 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_all(t_data *data)
{
	int i = 0;

	printf("player x = [%f]\n", data->player->pos_x);
	printf("player y = [%f]\n", data->player->pos_y);
	printf("width = [%d]\n", data->img->width);
	printf("height = [%d]\n", data->img->height);
	printf("floor color = [%d][%d][%d]\n", data->f_color[0], data->f_color[1], data->f_color[2]);
	printf("ceiling color = [%d][%d][%d]\n", data->c_color[0], data->c_color[1], data->c_color[2]);
	printf("facing = [%c]\n", data->facing);
	printf("north = [%s]\n", data->north);
	printf("south = [%s]\n", data->south);
	printf("west = [%s]\n", data->west);
	printf("east = [%s]\n\n", data->east);
	while (data->map[i])
		printf("[%s]\n", data->map[i++]);
}

int	main(int argc, char **argv)
{
	t_data	data;

	init_data(&data);
	check_input(&data, argc, argv[1]);
	print_all(&data);
	free_all(&data);
	return (0);
}
