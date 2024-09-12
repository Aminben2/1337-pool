
#include <stdlib.h>
#include <unistd.h>


int	ft_is_in_charset(char c)
{
	return(c == ' ' || c == '\t' || c == '\n');
}

int	count_words(char *str)
{
	int	i;
	int	word_count;

	i = 0;
	word_count = 0;
	while (str[i])
	{
		while (ft_is_in_charset(str[i]) && str[i])
			i++;
		if (str[i])
			word_count++;
		while (!ft_is_in_charset(str[i]) && str[i])
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

char	**ft_split(char *str)
{
	char	**split;
	int		word_count;
	int		i;
	int		start;
	int		j;

	word_count = count_words(str);
	split = malloc((word_count + 1) * sizeof(char *));
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i])
	{
		while (ft_is_in_charset(str[i]) && str[i])
			i++;
		start = i;
		while (!ft_is_in_charset(str[i]) && str[i])
			i++;
		if (i > start)
			split[j++] = malloc_word(str, start, i);
	}
	split[j] = NULL;
	return (split);
}
void put_str(char *str)
{
	while(*str)
		write(1, str++, 1);
}
int main(int ac, char **av)
{
	if(ac != 2)
		return (write(1, "\n", 1));
	char **ptr = ft_split(av[1]);
	int i= 0;
	while(ptr[i])
		i++;
	i--;
	while(i >= 0)
	{
		put_str(ptr[i]);
		if (i-- > 0)
			write(1, " ", 1);
	}
		
	return 0;
}

