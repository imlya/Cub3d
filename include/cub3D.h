/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:02:07 by magrabko          #+#    #+#             */
/*   Updated: 2025/04/09 21:44:14 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "parsing.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/*******************************************
 *                  EXEC                    *
 ********************************************/
void	ft_game(t_data *data);
void	ft_raycasting(t_data *data);
void	ft_set_texture(t_data *data, int x);
/*******************************************
 *                   INIT                    *
 ********************************************/
void	ft_init_player(t_data *data);
void	ft_init_ray(t_data *data);
void	ft_init_img(t_data *data);
void	ft_set_player(t_data *data);
/*******************************************
 *                  EVENTS                   *
 ********************************************/
void	ft_events_mlx(t_data *data);
void	ft_moves(t_data *data);
int		ft_keypress(int keycode, t_data *data);
int		ft_keyrelease(int keycode, t_data *data);
int		ft_destroy(t_data *data);
/*******************************************
 *                  DRAW                    *
 ********************************************/
void	ft_put_pixel(t_data *data, int x, int y, int color);
void	ft_draw_background(t_data *data);

// void	ft_add_texture(t_data *data, int i);

// /* TEMPORAIRE -> TESTS */
void	print_all(t_data *data);
#endif
