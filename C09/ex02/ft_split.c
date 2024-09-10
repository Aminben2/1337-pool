/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbenomar <mbenomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 20:28:56 by mbenomar          #+#    #+#             */
/*   Updated: 2024/08/15 15:45:03 by mbenomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_is_in_charset(char *charset, char c)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	count_words(char *str, char *charset)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	while (str[i])
	{
		while (ft_is_in_charset(charset, str[i]) && str[i])
			i++;
		if (str[i])
			word_count++;
		while (!ft_is_in_charset(charset, str[i]) && str[i])
			i++;
	}
	return (word_count);
}

char	*malloc_word(char *str, int start, int end)
{
	char	*word;
	int		i;

	word = malloc(end - start + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		word_count;
	int		i;
	int		start;
	int		j;

	word_count = count_words(str, charset);
	split = malloc((word_count + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (ft_is_in_charset(charset, str[i]) && str[i])
			i++;
		start = i;
		while (!ft_is_in_charset(charset, str[i]) && str[i])
			i++;
		if (i > start)
			split[j++] = malloc_word(str, start, i);
	}
	split[j] = NULL;
	return (split);
}
