/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenomar <mbenomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 14:01:17 by mbenomar          #+#    #+#             */
/*   Updated: 2024/07/31 14:12:46 by mbenomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*tmp_str;
	char	*tmp_to_find;

	if (*to_find == '\0')
		return (str);
	while (*str)
	{
		tmp_str = str;
		tmp_to_find = to_find;
		while (*tmp_to_find && *tmp_str == *tmp_to_find)
		{
			tmp_str++;
			tmp_to_find++;
		}
		if (*tmp_to_find == '\0')
			return (str);
		str++;
	}
	return (0);
}
