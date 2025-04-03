/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 18:47:02 by imatek            #+#    #+#             */
/*   Updated: 2025/04/03 19:09:20 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3D.h"

void ft_player_dir(t_data *data)
{
    if (data->facing == 'N')
	{
		data->player.plane_x = 0.66;
		data->player.plane_y = 0;
	}
	if (data->facing == 'S')
	{
		data->player.plane_x = -0.66;
		data->player.plane_y = 0;
	}
	if (data->facing == 'W')
	{
		data->player.plane_x = 0;
		data->player.plane_y = 0.66;
	}
	if (data->facing == 'E')
	{
		data->player.plane_x = 0;
		data->player.plane_y = -0.66;
	}
}
