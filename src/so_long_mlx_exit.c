/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_mlx_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 16:10:12 by zlee              #+#    #+#             */
/*   Updated: 2025/04/05 16:10:35 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_win(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->textures[0].img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->textures[1].img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->textures[2].img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->textures[3].img_ptr);
	mlx_destroy_image(data->mlx_ptr, data->textures[4].img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	data->map_data = ft_lstfirst(data->map_data);
	ft_lstclear(&(data->map_data), free);
	free(data->mlx_ptr);
	exit (0);
	return (0);
}
