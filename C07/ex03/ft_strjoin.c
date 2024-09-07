/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenomar <mbenomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 13:05:52 by mbenomar          #+#    #+#             */
/*   Updated: 2024/08/09 21:40:49 by mbenomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	count_bytes(char **array_of_strings, int number_of_strings)
{
	int	bytes;
	int	i;

	i = 0;
	bytes = 0;
	while (i < number_of_strings)
	{
		if (array_of_strings[i] != NULL)
			bytes += ft_strlen(array_of_strings[i]);
		i++;
	}
	return (bytes);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0'; 
	return (dest);
}

char	*ft_form_string(char *string, char **strs, char *sep, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (strs[i] != NULL)
			ft_strcat(string, strs[i]);
		if (i < size - 1)
			ft_strcat(string, sep);
		i++;
	}
	return (string);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*string;
	int		bytes;
	int		sep_bytes;

	if (size <= 0)
	{
		string = malloc(1);
		if (string)
			string[0] = '\0';
		return (string);
	}
	bytes = count_bytes(strs, size);
	sep_bytes = ft_strlen(sep) * (size - 1);
	string = malloc(bytes + sep_bytes + 1);
	if (string == NULL)
		return (string);
	string[0] = '\0';
	return (ft_form_string(string, strs, sep, size));
}
