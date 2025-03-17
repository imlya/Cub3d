/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:23:59 by imatek            #+#    #+#             */
/*   Updated: 2025/03/17 17:16:30 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "cub3D.h"
# include <stdbool.h>

# define WIDTH 1250
# define HEIGHT 720

typedef struct s_temp
{
	int			x;
	int			y;
	int			fd_map;
	char		*file;
	char		*line;
	char		**map_check;
}				t_temp;

// typedef struct s_sprite
// {
// }				t_sprite;

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	bool		up;
	bool		down;
	bool		right;
	bool		left;
	bool		rotate_right;
	bool		rotate_left;
}				t_player;

typedef struct s_img
{
	void		*image;
	char		*pixels;
	// char	*path;
	int			bpp;
	int			line_len;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct s_data
{
	void		*mlx;
	void		*window;
	t_img		*img;
	t_img		texture[5];
	// t_img	minimap;
	t_player	*player;
	// int			max_x;
	// int			max_y;
	// int			img_x;
	// int			img_y;
	int			*f_color;
	int			*c_color;
	char		facing;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	// t_sprite	*sprite;
	char		**map;
	t_temp		*temp;
}				t_data;

#endif