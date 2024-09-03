/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenomar <mbenomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 22:21:02 by mbenomar          #+#    #+#             */
/*   Updated: 2024/08/03 13:38:12 by mbenomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	has_char(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	check_valid(char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (has_char(base, base[i]) == 0 || base[i] == '+' || base[i] == '-'
			|| (base[i] >= 9 && base[i] <= 13) || base[i] == 32)
		{
			return (0);
		}
		i++;
	}
	if (i <= 1)
		return (0);
	return (1);
}

void	convert(int nbr, int base_len, char *base)
{
	long	nbr_long;

	nbr_long = nbr;
	if (nbr_long < 0)
	{
		ft_putchar('-');
		nbr_long *= -1;
	}
	if (nbr_long >= base_len)
	{
		convert(nbr_long / base_len, base_len, base);
	}
	ft_putchar(base[nbr_long % base_len]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_len;

	base_len = 0;
	if (!check_valid(base))
		return ;
	while (base[base_len])
		base_len++;
	convert(nbr, base_len, base);
}
