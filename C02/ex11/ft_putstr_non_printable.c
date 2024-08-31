/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenomar <mbenomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:13:25 by mbenomar          #+#    #+#             */
/*   Updated: 2024/07/29 22:31:43 by mbenomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	char	*hexa;
	int		i;

	i = 0;
	hexa = "0123456789abcdef";
	while (str[i])
	{
		if (str[i] < 32 || str[i] == 127)
		{
			write(1, "\\", 1);
			write(1, &hexa[(unsigned char)str[i] / 16], 1);
			write(1, &hexa[(unsigned char)str[i] % 16], 1);
		}
		else
			write(1, &str[i], 1);
		i++;
	}
}
