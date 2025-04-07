/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_ff_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 23:08:33 by zlee              #+#    #+#             */
/*   Updated: 2025/04/05 23:09:21 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*This is to search if the map still contains elements of P, E, or C
 * after floodfilling.*/
static int	search_anomaly(t_list *map)
{
	int		index;
	char	*temp_str;

	while (map)
	{
		index = -1;
		temp_str = (char *)map->content;
		while (temp_str[++index])
			if (temp_str[index] == 'P' || temp_str[index] == 'E'
				|| temp_str[index] == 'C')
				return (1);
		map = map->next;
	}
	return (0);
}

/*Flood Fill Algorithm*/
static void	flood_fill(t_list **map, int x, int y)
{
	int	temp_y;

	temp_y = y;
	*map = ft_lstfirst(*map);
	if (x < 0 || x >= (int)ft_strlen((char *)(*map)->content) || y < 0
	|| y >= ft_lstsize(*map))
		return ;
	while (temp_y-- > 0)
		*map = (*map)->next;
	if (((char *)(*map)->content)[x] == '1'
		|| ((char *)(*map)->content)[x] == '2'
		|| ((char *)(*map)->content)[x] == 'N')
		return ;
	((char *)(*map)->content)[x] = '2';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

/*Act as a dummy function to return 1 or 0
 * Replace all 0, P, and E with flood fill with 2
 * Check if 0, P, and E still exists. If so, returns 0. If not, returns 1*/
int	flood_fill_main(t_list *map)
{
	t_list	*temp;
	int		x;
	int		y;

	find_player_coordinate(map, &x, &y);
	temp = ft_lstdup(map);
	flood_fill(&temp, x, y);
	temp = ft_lstfirst(temp);
	if (search_anomaly(temp))
	{
		ft_lstclear(&temp, free);
		return (error_exit(7));
	}
	ft_lstclear(&temp, free);
	return (1);
}
