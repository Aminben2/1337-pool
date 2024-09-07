/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenomar <mbenomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 12:04:03 by mbenomar          #+#    #+#             */
/*   Updated: 2024/08/12 14:12:38 by mbenomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;
	int	n;

	arr = NULL;
	if (min >= max)
		return (arr);
	n = max - min;
	arr = malloc(sizeof(int) * n);
	if (arr == NULL)
		return (0);
	i = 0;
	while (i < n)
	{
		arr[i] = min + i;
		i++;
	} 
	return (arr);
}
