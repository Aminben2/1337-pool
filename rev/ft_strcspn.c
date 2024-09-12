#include <stdio.h>
#include <string.h>

int has_char(const char *str, char c)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return 1;
		i++;
	}
	return 0;
}	

int	ft_strcspn(const char *s, const char *reject)
{
	int i = 0;
	while (s[i])
	{
		if (has_char(reject,s[i]))
		{
			return i;
		}
		i++;
	}
	return i;
}

int main(void)
{
	printf("%d\n",ft_strcspn("miane","kkjka"));
	printf("%ld",strcspn("miane","kkjka"));
	return 0;
}