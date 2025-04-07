/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_init_numbers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:36:35 by zlee              #+#    #+#             */
/*   Updated: 2025/04/08 00:42:12 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_numbers(t_data *mlx)
{
	mlx->numbers[0] = create_sprite("./textures/numbers/digit_0.xpm",
			mlx->mlx_ptr);
	mlx->numbers[1] = create_sprite("./textures/numbers/digit_1.xpm",
			mlx->mlx_ptr);
	mlx->numbers[2] = create_sprite("./textures/numbers/digit_2.xpm",
			mlx->mlx_ptr);
	mlx->numbers[3] = create_sprite("./textures/numbers/digit_3.xpm",
			mlx->mlx_ptr);
	mlx->numbers[4] = create_sprite("./textures/numbers/digit_4.xpm",
			mlx->mlx_ptr);
	mlx->numbers[5] = create_sprite("./textures/numbers/digit_5.xpm",
			mlx->mlx_ptr);
	mlx->numbers[6] = create_sprite("./textures/numbers/digit_6.xpm",
			mlx->mlx_ptr);
	mlx->numbers[7] = create_sprite("./textures/numbers/digit_7.xpm",
			mlx->mlx_ptr);
	mlx->numbers[8] = create_sprite("./textures/numbers/digit_8.xpm",
			mlx->mlx_ptr);
	mlx->numbers[9] = create_sprite("./textures/numbers/digit_9.xpm",
			mlx->mlx_ptr);
}

void	process_number(t_data *mlx)
{
	char	*text;
	t_pos	pos;
	int		i;

	i = -1;
	pos.x = 10;
	pos.y = 10;
	text = ft_itoa(mlx->counter);
	while (text[++i])
	{
		put_img_on_canvas(mlx, &mlx->numbers[text[i] - '0'],
			&mlx->display, pos);
		pos.x += (MUL / 2);
	}
	free(text);
}
