/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:02:07 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/13 14:50:37 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "parsing.h"
# include "structures.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define RED_INT 0xFF0000

/*******************************************
 *                   MLX                    *
 ********************************************/
void	ft_init_mlx(t_data *data, t_img *image);
void	ft_put_pixel(t_img *image, int x, int y, int color);
void	ft_draw_player(t_img *image, int x, int y, int size, int color);

/*******************************************
 *                  EXEC                    *
 ********************************************/
void	ft_ray_direction(t_player *player);

// /* TEMPORAIRE -> TESTS */
// void	print_all(t_data *data);
#endif
