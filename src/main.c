/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:37:31 by imatek            #+#    #+#             */
/*   Updated: 2025/03/12 21:31:41 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// void	print_all(t_data *data)
// {
// 	int i = 0;

// 	printf("player x = [%d]\n", data->player_x);
// 	printf("player y = [%d]\n", data->player_y);
// 	printf("width = [%d]\n", WIDTH);
// 	printf("height = [%d]\n", HEIGHT);
// 	printf("floor color = [%d][%d][%d]\n", data->f_color[0], data->f_color[1], data->f_color[2]);
// 	printf("ceiling color = [%d][%d][%d]\n", data->c_color[0], data->c_color[1], data->c_color[2]);
// 	printf("facing = [%c]\n", data->facing);
// 	printf("north = [%s]\n", data->north);
// 	printf("south = [%s]\n", data->south);
// 	printf("west = [%s]\n", data->west);
// 	printf("east = [%s]\n\n", data->east);
// 	while (data->map[i])
// 		printf("[%s]\n", data->map[i++]);
// }

int main()
{
    t_data data;
    t_img image;
    
    ft_init_mlx(&data, &image);
    // check_input(&data, argc, argv[1]);
	// print_all(&data);
	free_all(&data);
    mlx_loop(data.mlx);
    return (0);
}
