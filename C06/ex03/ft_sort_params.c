/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenomar <mbenomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/03 19:37:19 by mbenomar          #+#    #+#             */
/*   Updated: 2024/08/12 16:40:14 by mbenomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	compare_strings(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str1[i] == str2[i])
	{
		i++;
	}
	return (str1[i] - str2[i]);
}

char	**sort(char **arr, int size)
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	while (i < size - 1)
	{
		j = 1;
		while (j < size - i)
		{
			if (compare_strings(arr[j], arr[j + 1]) > 0)
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

int	main(int ac, char **ag)
{
	int		i;
	int		j;
	char	**sorted;

	sorted = sort(ag, ac);
	i = 1;
	while (i < ac)
	{
		j = 0;
		while (sorted[i][j])
		{
			ft_putchar(sorted[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
	return (0);
}
