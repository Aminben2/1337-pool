/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenomar <mbenomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 12:17:08 by mbenomar          #+#    #+#             */
/*   Updated: 2024/08/13 16:02:11 by mbenomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*arr;
	int	i;
	int	n;

	arr = NULL;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	n = max - min;
	arr = malloc(sizeof(int) * n);
	if (arr == NULL)
		return (-1);
	i = 0;
	while (i < n)
	{
		arr[i] = min + i;
		i++;
	}
	*range = arr;
	return (n);
}

int a = 0;

int *p = &a;

int **op = &p;