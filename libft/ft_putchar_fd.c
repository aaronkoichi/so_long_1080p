/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zlee <zlee@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:19:35 by zlee              #+#    #+#             */
/*   Updated: 2025/03/21 12:50:29 by zlee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	(void)!write(fd, &c, 1);
}
/*
int	main(void)
{
	ft_putchar_fd('g', 1);
	ft_putchar_fd('H', 1);
	ft_putchar_fd('\n', 1);
	ft_putchar_fd('0', 1);
}
*/
