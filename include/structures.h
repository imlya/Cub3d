/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:23:59 by imatek            #+#    #+#             */
/*   Updated: 2025/04/03 19:27:31 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "cub3D.h"
# include <stdbool.h>

# define WIDTH 1940
# define HEIGHT 1280

typedef struct s_pars
{
	char		*line;
	int			x;
	int			y;
	int			player_x;
	int			player_y;
	int			fd_map;
	char		*file;
	char		**rgb;
	char		**map_check;
}				t_pars;

typedef struct s_text
{
	void		*img;
	char		*pixels;
	int			bpp;
	int			line_len;
	int			endian;
	int			width;
	int			height;
	char		*path;

}				t_text;

typedef struct s_hand
{
	t_text		frames[4];
	double		delay;
	int			current_frame;
}				t_hand;

typedef struct s_effect
{
	t_text		frames[11];
	double		delay;
	int			current_frame;
}				t_effect;

typedef struct s_assets
{
	t_text		*w_north;
	t_text		*w_south;
	t_text		*w_west;
	t_text		*w_east;
	t_text		*sky;
	t_text		*floor;
	t_text		*door;
	t_text		*donut;
	t_effect	*effect;
	t_hand		*hand;
}				t_assets;

typedef struct s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		time;
	double		old_time;
	bool		up;
	bool		down;
	bool		right;
	bool		left;
	bool		rotate_right;
	bool		rotate_left;
}				t_player;

typedef struct s_ray
{
	double		dir_x;
	double		dir_y;
	double		camera_x;
	double		delta_dist_x;
	double		delta_dist_y;
	double		side_dist_x;
	double		side_dist_y;
	double		perpwalldist;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	// int			wall_side;
	// int			wall_dist;
	// int			size_line;
	// int			start_line;
	// int			end_line;
	// int			start;
	// int			end;
}				t_ray;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*window;
	t_text		img[5];
	char		**map;
	int			height;
	int			width;
	char		facing;
	// t_text		minimap;
	// int			rgb_floor[3];
	// int			rgb_sky[3];
	// double		step;
	// int			texture;
	// int			tex_x;
	// int			tex_y;
	// double		tex_pos;
	// double		wall_x;
	int			*f_color;
	int			*c_color;
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	t_pars		*pars;
	t_assets	*assets;
	t_player	player;
	t_ray		ray;
}				t_data;

#endif
