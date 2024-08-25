/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenomar <mbenomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:45:24 by mbenomar          #+#    #+#             */
/*   Updated: 2024/07/25 14:40:42 by mbenomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_put_char(char n)
{
	write(1, &n, 1);
}

void	ft_print_comb2(void)
{
	int	left;
	int	right;

	left = 0;
	right = 1;
	while (left <= 98)
	{
		right = left + 1;
		while (right <= 99)
		{
			ft_put_char(left / 10 + '0');
			ft_put_char(left % 10 + '0');
			write(1, " ", 1);
			ft_put_char(right / 10 + '0');
			ft_put_char(right % 10 + '0');
			if (left != 98)
			{
				write(1, ", ", 2);
			}
			right++;
		}
		left++;
	}
}
