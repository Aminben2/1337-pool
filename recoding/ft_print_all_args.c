#include <unistd.h>
#include <stdio.h>

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

void ft_putnbr(int nb)
{
	long nbb = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		nbb *= -1;
	}
	if (nbb >= 10)
		ft_putnbr(nbb / 10);
	ft_putchar(nbb % 10 + '0');
}

int ft_atoi(char *nb,int *flag)
{
	int number = 0;
	int signs = 0;
	int i = 0;
	while(nb[i] == 32 || (nb[i] >= 9 && nb[i] <= 13))
		i++;
	while (nb[i] == '-' || nb[i] == '+')
	{
		if (nb[i] == '-')
			signs++;
		if (signs > 1)
		{
			ft_putstr("Error : Invalid Integer");
			*flag = 1;
			return 0;
		}
		i++;
	}
	while(nb[i] >= '0' && nb[i] <= '9')
	{
		number *= 10;
		number += nb[i] - '0';
		i++;
	}

	if (!(nb[i] >= '0' && nb[i] <= '9') && nb[i] != '\0')
	{
		ft_putstr("Error : Invalid Integer");
		*flag = 1;
		return 0;
	}

	if (signs == 1)
		return -number;
	return number;
}

int main(int ac, char **av)
{
	if (ac > 1)
	{
		int total = 0;
		int i = 1;
		int curr;
		int f = 0;
		int *flag = &f;

		while(i < ac)
		{
			curr = ft_atoi(av[i], flag);
			total += curr;
			i++;
		}
		if (*flag == 0)
			ft_putnbr(total);
	}
	else
		ft_putstr("No numbers provided");
	return 0;
}