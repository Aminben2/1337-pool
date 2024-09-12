#include <unistd.h>
char *ft_tolower(char *str)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return str;
}

int ft_is_space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return 1;
	return 0;
}

char *ft_rstr_cap(char *str)
{
	int i = 0;
	while (str[i])
	{
		while (ft_is_space(str[i]) && str[i])
			i++;
		while (!ft_is_space(str[i]) && str[i])
			i++;
		if (str[i - 1])
			str[i - 1] -= 32;
	}
	return str;
}
void ft_putstr(char *str)
{
	int i = 0;
	while (str[i])
		write(1, &str[i++],1);
}
int main(int ac, char **ag)
{
	if (ac > 1)
	{
		int i = 1;
		char *str;
		while (i < ac)
		{
			str = ft_rstr_cap(ft_tolower(ag[i]));
			ft_putstr(str);
			if (i < ac - 1)
				write(1, "\n" , 1);
			i++;
		}
		
	}
	write(1 , "\n", 1);
	return 0;
}