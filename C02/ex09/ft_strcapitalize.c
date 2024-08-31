/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.cc                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenomar <mbenomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 23:18:52 by mbenomar          #+#    #+#             */
/*   Updated: 2024/07/30 10:20:32 by mbenomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (c += 32);
	return (c);
}

char	to_upper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c -= 32);
	return (c);
}

int	is_alphanumeric(char c)
{
	if ((c >= 'A' && c <= 'Z') 
		|| (c >= 'a' && c <= 'z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	while (str[i] != '\0')
	{
		if (is_alphanumeric(str[i]) == 1)
		{
			if (flag)
			{
				str[i] = to_upper(str[i]);
				flag = 0;
			}
			else
				str[i] = to_lower(str[i]);
		}
		else
			flag = 1;
		i++;
	}
	return (str);
}
