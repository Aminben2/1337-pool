#include <unistd.h>

int ft_atoi(char *nbr)
{
	int number = 0;
	int sign = 0;
	int i = 0;

	while ((nbr[i] >= 9 && nbr[i] <= 13) || nbr[i] == 32)
		i++;
	if (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			sign++;
		i++;
	}
	while (nbr[i] >= '0' && nbr[i] <= '9')
	{
		number *= 10;
		number += nbr[i] - '0';
		i++;
	}
	if (sign > 0)
		return -number;
	return number;
}
void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putnbr(int nb)
{
	long nbl = nb;
	if (nb < 0)
	{
		ft_putchar('-');
		nbl *= -1;
	}
	if (nbl >= 10)
		ft_putnbr(nbl / 10);
	ft_putchar(nbl % 10 + '0');
}

int main(int ac, char **ag)
{
	if (ac == 2)
	{
		int n = ft_atoi(ag[1]);
		int i = 1;
		if (n > 0)
		{
			while (i <= 9)
			{
				ft_putchar(i + '0');
				write(1, " x ", 3);
				ft_putnbr(n);
				write(1, " = ", 3);
				ft_putnbr(n * i);
				if (i != 9)
					ft_putchar('\n');
				i++;
			}
		}
	}
	write(1, "\n", 1);
	return (0);
}