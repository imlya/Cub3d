/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:02:07 by magrabko          #+#    #+#             */
/*   Updated: 2025/03/11 12:55:18 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
// # include "parsing.h"
# include "structures.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/*******************************************
*                   MLX                    *        
********************************************/
void	ft_init_mlx(t_data *data, t_img *image);
void	init_data(t_data *data, t_player *player);
void	ft_put_pixel(t_img *image, int x, int y, int color);

/*******************************************
*                  EXEC                    *        
********************************************/
void	ft_ray_direction(t_player *player);

/*******************************************
*                PARSING                   *        
********************************************/

#endif
