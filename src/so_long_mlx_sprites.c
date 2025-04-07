/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_mlx_sprites.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 15:58:42 by zlee              #+#    #+#             */
/*   Updated: 2025/04/08 00:41:30 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_sprite	create_sprite(char *path, void *mlx_ptr)
{
	t_sprite	sprite;

	sprite.img_ptr = mlx_xpm_file_to_image(mlx_ptr, path,
			&sprite.img_size.x, &sprite.img_size.y);
	sprite.pixels = mlx_get_data_addr(sprite.img_ptr, &sprite.bpp,
			&sprite.line_size, &sprite.endian);
	return (sprite);
}

void	set_sprites(t_data *mlx)
{

	mlx->textures[0] = create_sprite("./textures/ground_1.xpm", mlx->mlx_ptr);
	mlx->textures[1] = create_sprite("./textures/wall.xpm", mlx->mlx_ptr);
	mlx->textures[2] = create_sprite("./textures/charac/s_frame_1.xpm",
			mlx->mlx_ptr);
	mlx->textures[3] = create_sprite("./textures/food.xpm", mlx->mlx_ptr);
	mlx->textures[4] = create_sprite("./textures/exit.xpm", mlx->mlx_ptr);
}
