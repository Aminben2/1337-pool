#include <stdio.h>
#include <stdlib.h>

int ft_is_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return 1;
	return 0;
}

int ft_count_words(char *str)
{
	int i = 0, count = 0;
	while (str[i])
	{
		while (ft_is_space(str[i]))
			i++;
		if (str[i])
			count++;
		while (!ft_is_space(str[i]) && str[i])
			i++;
	}
	return count;
}

char *ft_word_malloc(char *str, int start, int end)
{
	char *word;
	word = malloc(end - start + 1);
	if (!word)
		return NULL;
	int i = 0;
	while ( i < end - start)
	{
		word[i] = str[start + i];
		i++;
	}
	word[i] = '\0';
	return word;
}

char    **ft_split(char *str)
{
	char **split;
	if (str == NULL)
    {
		split = malloc(sizeof(char *));
		if (!split)
			return NULL;
		split[0] = NULL;
		return split;
	}

	int word_count = ft_count_words(str);
	split = malloc(sizeof(char *) * (word_count + 1));
	if (!split)
		return NULL;
	int i = 0,start,j = 0;
	while (str[i])
	{
		while (ft_is_space(str[i]))
			i++;
		start = i;
		while (!ft_is_space(str[i]) && str[i])
			i++;
		if (i > start)
			split[j++] = ft_word_malloc(str,start,i) ;
	}
	split[j] = NULL;
	return split;
}

int main()
{
    // Test 1: Basic case with normal words
    printf("Test 1:\n");
    char *str1 = "           im in 13\n37 scho\tol";
    char **ptr1 = ft_split(str1);
    for(int i = 0; ptr1[i] != NULL ; i++)
    {
        printf("%s\n", ptr1[i]);
    }
    printf("\n");
    // Expected Output:
    // im
    // in
    // 13
    // 37
    // scho
    // ol

    // Test 2: Empty string
    printf("Test 2:\n");
    char *str2 = "";
    char **ptr2 = ft_split(str2);
    for(int i = 0; ptr2[i] != NULL ; i++)
    {
        printf("%s\n", ptr2[i]);
    }
    printf("\n");
    // Expected Output:
    // (Nothing should be printed)

    // Test 3: String with only whitespaces
    printf("Test 3:\n");
    char *str3 = " \t \n  ";
    char **ptr3 = ft_split(str3);
    for(int i = 0; ptr3[i] != NULL ; i++)
    {
        printf("%s\n", ptr3[i]);
    }
    printf("\n");
    // Expected Output:
    // (Nothing should be printed)

    // Test 4: String with leading, trailing, and multiple internal spaces
    printf("Test 4:\n");
    char *str4 = "   Hello   World  ";
    char **ptr4 = ft_split(str4);
    for(int i = 0; ptr4[i] != NULL ; i++)
    {
        printf("%s\n", ptr4[i]);
    }
    printf("\n");
    // Expected Output:
    // Hello
    // World

    // Test 5: String with non-printable characters
    printf("Test 5:\n");
    char *str5 = "Hello\nWorld\t42";
    char **ptr5 = ft_split(str5);
    for(int i = 0; ptr5[i] != NULL ; i++)
    {
        printf("%s\n", ptr5[i]);
    }
    printf("\n");
    // Expected Output:
    // Hello
    // World
    // 42

 // Test 5: String with non-printable characters
    printf("Test 6:\n");
    char *str6 = NULL;
    char **ptr6 = ft_split(str6);
    for(int i = 0; ptr6[i] != NULL ; i++)
    {
        printf("%s\n", ptr6[i]);
    }
    printf("\n");
    // Expected Output:
    // Hello
    // World
    // 42
    return 0;
}
