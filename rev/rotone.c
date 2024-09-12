#include <unistd.h>

void	convert(char *c)
{
	int i;

	i = 0;
	while (c[i])
	{
		if ((c[i] >= 'a' && c[i] <= 'y') || (c[i] >= 'A' && c[i] <= 'Y'))
		{
			c[i] += 1;
			write(1, &c[i], 1);
		}
		if (c[i] == 'z' || c[i] == 'Z')
		{
			c[i] -= 25;
			write(1, &c[i], 1);
		}
		i++;
	}
}
int	main(int argc, char *argv[])
{
	int	i;

	if (argc == 2)
	{
		convert(argv[1]);
	}
	write(1, "\n", 1);
	return 0;
}
