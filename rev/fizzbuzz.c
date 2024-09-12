#include <unistd.h>

void put_char(char c)
{
	write(1, &c, 1);
}
void put_nbr(int nb)
{
	if (nb / 10)
		put_nbr(nb / 10);
	put_char(nb % 10 + '0');
}

int	main(void)
{
	int	i;
	i = 1;
	while (i <= 100)
	{
		if (i % 3 == 0 && i % 5 == 0)
			write(1, "fizzbuzz", 8);
		else if (i % 3 == 0)
			write(1, "fizz", 4);
		else if (i % 5 == 0)
			write(1, "buzz", 4);
		else 
			put_nbr(i);
		write(1, "\n", 1);
		i++;
	}
	return 0;
}