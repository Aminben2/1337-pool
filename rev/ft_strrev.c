#include <stdio.h>

char    *ft_strrev(char *str)
{
	int len = 0;
	while (str[len])
		len++;
	int i = 0;
	char tmp ;
	while (i < len / 2)
	{
		tmp = str[i];
		str[i] = str[len - 1];
		str[len - 1] = tmp;
		i++;
		len--;
	}
	return (str);
}

int main(void)
{
	char str[] = "amine";
	ft_strrev(str);
	printf("%s",str);
	return 0;
}