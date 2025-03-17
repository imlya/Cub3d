/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:37:31 by imatek            #+#    #+#             */
/*   Updated: 2025/03/17 17:09:52 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	print_all(t_data *data)
{
	int	i;

	i = 0;
	printf("width = [%d]\n", WIDTH);
	printf("height = [%d]\n", HEIGHT);
	printf("player x = [%f]\n", data->player->pos_x);
	printf("player y = [%f]\n", data->player->pos_y);
	printf("floor color = [%d][%d][%d]\n", data->f_color[0], data->f_color[1],
		data->f_color[2]);
	printf("ceiling color = [%d][%d][%d]\n", data->c_color[0], data->c_color[1],
		data->c_color[2]);
	printf("facing = [%c]\n", data->facing);
	printf("north = [%s]\n", data->north);
	printf("south = [%s]\n", data->south);
	printf("west = [%s]\n", data->west);
	printf("east = [%s]\n\n", data->east);
	while (data->map[i])
		printf("[%s]\n", data->map[i++]);
}

int	main(void)
{
	t_data	data;
	t_img	image;

	ft_init_mlx(&data, &image);
	// check_input(&data, argc, argv[1]);
	// print_all(&data);
	ft_draw_player(&image, WIDTH / 2, HEIGHT / 2, 8, RED_INT);
	ft_events_mlx(&data);
	free_all(&data);
	return (0);
}
