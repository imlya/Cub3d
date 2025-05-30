/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrabko <magrabko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 17:09:20 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/29 20:13:20 by magrabko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	is_open(char **map, char op, int i, int j)
{
	if (op == '&')
	{
		if ((!map[i][j + 1] || map[i][j + 1] == ' ')
			&& (j - 1 < 0 || map[i][j - 1] == ' ')
			&& (!map[i + 1] || map[i + 1][j] == ' ')
			&& (i - 1 < 0 || map[i - 1][j] == ' '))
			return (0);
	}
	else if (op == '|')
	{
		if ((!map[i][j + 1] || map[i][j + 1] == ' ')
			|| (j - 1 < 0 || map[i][j - 1] == ' ')
			|| (!map[i + 1] || map[i + 1][j] == ' ')
			|| (i - 1 < 0 || map[i - 1][j] == ' '))
			return (0);
	}
	return (1);
}

int	is_rgb_valid(char **rgb)
{
	long	r;
	long	g;
	long	b;

	r = ft_atol(rgb[0]);
	g = ft_atol(rgb[1]);
	b = ft_atol(rgb[2]);
	if ((r < 0 || r > 255) || (g < 0 || g > 255) || (b < 0 || b > 255))
		return (0);
	return (1);
}

char	*get_element_info(t_data *data, char *temp, int *index)
{
	char	*info;
	int		end;

	end = 0;
	while (temp[end] && !is_c_inset(temp[end], ALL_SPACES))
		end++;
	info = ft_strndup(temp, end);
	check_alloc(info, data);
	*index = end;
	return (info);
}

int	get_element(t_data *data, char *line, int n)
{
	char	*temp;

	temp = NULL;
	if (is_key_valid(line, "NO") && !data->north)
		temp = ft_strnstr(line, "NO", n);
	else if (is_key_valid(line, "SO") && !data->south)
		temp = ft_strnstr(line, "SO", n);
	else if (is_key_valid(line, "WE") && !data->west)
		temp = ft_strnstr(line, "WE", n);
	else if (is_key_valid(line, "EA") && !data->east)
		temp = ft_strnstr(line, "EA", n);
	else if (is_key_valid(line, "F")&& !data->f_color)
		temp = ft_strnstr(line, "F", n);
	else if (is_key_valid(line, "C")&& !data->c_color)
		temp = ft_strnstr(line, "C", n);
	else if (temp == NULL)
		return (0);
	if (temp[0] == 'F' || temp[0] == 'C')
	{
		if (!is_c_inset(line[go_edge_char(line, FIRST_C)], "FC"))
			return (0);
		return (n = (n - ft_strlen(temp)) + 1);
	}
	return (n = (n - ft_strlen(temp)) + 2);
}

int	go_end_map(t_data *data, int i)
{
	int	map_end;

	map_end = i;
	while (data->pars->map_check[i] && is_line_empty(data->pars->map_check[i]))
		i++;
	if (data->pars->map_check[i])
		return (0);
	data->height -= (i - map_end);
	return (1);
}
