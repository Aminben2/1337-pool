#include <stdio.h>
#include <stdlib.h>

char *ft_itoa(int nbr)
{
	char *str;
	int nb = nbr;
	int len;

	len = (nbr < 0 ? 2 : 1);
	while (nbr && ++len)
		nbr /= 10;
	str = malloc(len);
	if (str == NULL)
		return NULL;
	str[len - 1] = '\0';
	len--;
	if (nb <= 0)
	{
	str[0] = (nb < 0 ? '-' : '0');
		nb = -nb;	
	}
		
	while (nb)
	{
		str[--len] = (nb % 10) + '0';
		nb /= 10;
	}
	return str;
}

int main(void)
{
	// char *str = ft_itoa(-446465);
	printf("%s",ft_itoa(-446465));
}
