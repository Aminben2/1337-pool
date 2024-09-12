#include <stdio.h>
#include <stdlib.h>

char *ft_itoa(int nb)
{
	char *number;
	long nbr = nb;
	int len;

	len = (nb < 0 ? 2 : 1);
	while (nb && ++len)
		nb /= 10;
	number = malloc(len);
	number[--len] = '\0';
	if (nbr <= 0)
	{
		number[0] = (nbr < 0 ? '-' : '0');
		nbr = -nbr;
	}
	while (nbr)
	{
		number[--len] = nbr % 10 + '0';
		nbr /= 10;
	}
	return number;
}

int main(void)
{
	printf("%s",ft_itoa(-451));
	return 0;
}