/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 16:20:26 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/10 14:51:18 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_ptr(void **ptr)
{
	if (ptr != NULL || *ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	free_tab(char ***tab)
{
	size_t	i;

	if (tab == NULL || *tab == NULL)
		return ;
	i = 0;
	while ((*tab)[i])
	{
		free_ptr((void **)&(*tab)[i]);
		i++;
	}
	free_ptr((void **)tab);
}

void	free_temp(t_data *data)
{
	if (data->temp != NULL)
	{
		free_ptr((void **)&data->temp->file);
		free_ptr((void **)&data->temp->line);
		free_tab(&data->temp->map_check);
		free_ptr((void **)&data->temp);
	}
}

void	free_all(t_data *data)
{
	if (data->temp != NULL)
		free_temp(data);
	if (data->map != NULL)
		free_tab(&data->map);
/* 	if (data->sprite != NULL)
		; */
}
