/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:23:59 by imatek            #+#    #+#             */
/*   Updated: 2025/03/11 12:50:47 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "cub3D.h"

# define WIDTH 1250
# define HEIGHT 720

typedef struct s_player
{
	int			x;
	int			y;
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
}				t_data;

#endif