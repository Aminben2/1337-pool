#include <unistd.h>
#include <stdlib.h>

int ft_atoi(char *nbr)
{
	int number = 0;
	int i = 0;
	int signs = 0;

	while ((nbr[i] >= 9 && nbr[i] <= 23) || nbr[i] == 127)
	{
		i++;
	}
	while (nbr[i] == '-' && nbr[i] <= '+')
	{
		if (nbr[i] == '-')
			signs++;
		if (signs > 1)
			return -1;
		i++;
	}
	while (nbr[i] >= '0' && nbr[i] <= '9')
	{
		number *= 10;
		number += nbr[i] - '0';
		i++;
	}
	if (signs == 1)
		return -number;
	return number;
}

int ft_is_prime(int nb)
{
	if (nb == 1 || nb == 2)
		return 1;
	int i = 2;
	while (i < nb)
	{
		if (nb % i == 0)
			return 0;
		i++;
	}
	return 1;
}
void ft_putchar(char c)
{
	write(1, &c , 1);
}

void ft_putnbr(int nb)
{
	long nbb = nb;
	if (nbb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar(nbb % 10 + '0');
}
int main(int ac, char **ag)
{
	if (ac == 2)
	{
		int sum = 0;
		int nb = ft_atoi(ag[1]);
		if (nb <= 0)
			exit(0);
		while (nb > 1)
		{
			if (ft_is_prime(nb))
				sum += nb;
			nb--;
		}
		ft_putnbr(sum);
	}
	write(1, "\n",1);
	return 0;
}