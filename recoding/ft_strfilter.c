#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}
void ft_putstr(char *str)
{
	int i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int ft_strlen(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return i;
}

void ft_print_all_args(char **av , int ac)
{
	int i = 2;
	while (i < ac)
	{
		ft_putstr(av[i]);
		ft_putchar('\n');
		i++;
	}
}

int ft_check_prefix(char *pre, char *str)
{
	int i = 0;
	int flag = 1;
	while (pre[i])
	{
		if (pre[i] != str[i])
			flag = 0;
		i++;
	}
	return flag;
}

int main(int ac, char **av)
{
	if (ac >= 2)
	{
		if (ft_strlen(av[1]) == 0)
		{
			ft_print_all_args(av, ac);
			return 0;
		}
		int flag = 0;
		int i = 2;
		while(av[i])
		{
			if (ft_check_prefix(av[1], av[i]))
			{
				ft_putstr(av[i]);
				ft_putchar('\n');
				flag++;
			}
			i++;
		}
		if (flag == 0)
			ft_putstr("No match found.");
	}
	else 
		ft_putstr("No prefix provided");
	return 0;
}