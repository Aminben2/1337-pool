int is_char_in(const char *str, char c)
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

const char	*ft_strpbrk(const char *s1, const char *s2)
{
	int i = 0;
	while (*s1)
	{
		if (is_char_in(s2,*s1))
			return s1;	
		s1++;
	}
	return 0;
}
#include <stdio.h>

int	main(void)
{
	const char *str = ft_strpbrk("amine","m");
	printf("%s",str);
	return 0;
}