#include <unistd.h>

int check_is_upper(char c)
{
	if (c >= 'A' && c <= 'Z')
		return 1;
	return 0;
}
char *ft_tolowercase(char *str)
{
	int i  = 0;
	while (str[i])
	{
		if (check_is_upper(str[i]))
			str[i] = str[i] + 32;
		i++;
	}
	return str;
}

int check_is_space(char c)
{
	if (c == ' ' || c == '\t')
		return 1;
	return 0; 
}

void ft_putstr(char *str)
{
	while (*str)
		write(1 , str++, 1);
	
}

char *ft_str_cap(char *str)
{
	int i = 0;
	while (str[i])
	{
		while (check_is_space(str[i]) && str[i])
			i++;
		if (str[i])
			str[i] -= 32;
		while (!check_is_space(str[i]) && str[i])
			i++;
	}
	return str;
}
int main(int ac, char **av)
{
	if (ac > 1)
	{
		int i  = 1;
		char *new;
		char *new_cap;
		while (i < ac)
		{
			new = ft_tolowercase(av[i]);
			new_cap = ft_str_cap(new);
			ft_putstr(new_cap);
			if (i < ac - 1)
				write(1, "\n", 1);
			i++;
		}
	}	
	write(1, "\n", 1);
	return 0;
}