/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imatek <imatek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:23:59 by imatek            #+#    #+#             */
/*   Updated: 2025/03/10 12:39:36 by imatek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "cub3D.h"

typedef struct s_data
{
	void	*mlx;
	void	*window;
}			t_data;

void		ft_init_mlx(t_data *data);
int			ft_destroy(t_data *data);

#endif