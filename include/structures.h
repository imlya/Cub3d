/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:23:59 by imatek            #+#    #+#             */
/*   Updated: 2025/03/13 11:09:22 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "cub3D.h"

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
	int			pos_x;
	int			pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;

}				t_player;

typedef struct s_img
{
	void		*image;
	char		*pixels;
	int			bpp;
	int			line_len;
	int			endian;
}				t_img;

typedef struct s_data
{
	void		*mlx;
	void		*window;
	t_img		*image;
	t_player	*player;
	// int			width;
	// int			height;
	// int			max_x;
	// int			max_y;
	// int			img_x;
	// int			img_y;
	// int			*f_color;
	// int			*c_color;
	// char		facing;
	// char		*north;
	// char		*south;
	// char		*west;
	// char		*east;
	// t_sprite	*sprite;
	char		**map;
	t_temp		*temp;
}				t_data;

#endif