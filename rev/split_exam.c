int check_if_sep(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return 1;
	return 0;
}
char *malloc_word(char *str, int start, int end)
{
	char *word = malloc(end - start + 1);
	int i = 0;
	while (start < end)
	{
		word[i] = str[start];
		i++;
		start++;
	}
	word[i] = '\0';
	return (word);
}

int count_words(char *str)
{
	int i;
	int words;

	i = 0;
	while (str[i])
	{
		while (check_if_sep(str[i]) && str[i])
		{
			i++;
		}
		if (str[i])
			words++;
		while (!check_if_sep(str[i]) && str[i])
		{
			i++;
		}
	}
	return words;
}
char    **ft_split(char *str)
{
	char **array_of_strings;
	int words_count = count_words(str);
	int i = 0;
	int j = 0;
	int start;

	array_of_strings = (char **) malloc((count_words + 1) * sizeof(char *));
	while (str[i])
	{
		while (check_if_sep(str[i]) && str[i])
		{
			i++;
		}
		start = i;
		while (!check_if_sep(str[i]) && str[i])
		{
			i++;
		}
		if (i > start)
		{
			array_of_strings[j] = malloc_word(str,start,i);
			j++;
		}
	}
	
	return (array_of_strings);
}