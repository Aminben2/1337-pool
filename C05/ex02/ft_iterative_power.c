/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenomar <mbenomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 14:38:51 by mbenomar          #+#    #+#             */
/*   Updated: 2024/08/05 14:10:23 by mbenomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	fac;

	if (power < 0)
		return (0);
	if (power == 0 && nb == 0)
		return (1);
	fac = 1;
	while (power)
	{
		fac *= nb;
		power--;
	}
	return (fac);
}
