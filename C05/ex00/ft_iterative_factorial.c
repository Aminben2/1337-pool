/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenomar <mbenomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 13:39:50 by mbenomar          #+#    #+#             */
/*   Updated: 2024/08/05 17:14:04 by mbenomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	fac;

	if (nb < 0)
		return (0);
	fac = 1;
	while (nb)
	{
		fac *= nb;
		nb--;
	}
	return (fac);
}
