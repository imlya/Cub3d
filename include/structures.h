/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:23:59 by imatek            #+#    #+#             */
/*   Updated: 2025/03/10 14:51:53 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "cub3D.h"

# define WIDTH 800
# define HEIGHT 800

typedef struct s_temp
{
	int			x;
	int			y;
	int			fd_map;
	char		*file;
	char		*line;
	char		**map_check;
}				t_temp;

typedef struct s_player
{
	int		x;
	int		y;

}			t_player;

typedef struct s_data
{
	void	*mlx;
	void	*window;
}			t_data;

#endif