#include <unistd.h>

void print_mirror(char c)
{
	if ((c >= 'a' && c <= 'm') || (c >= 'n' && c<= 'z')){
		c = ('m' - (c - 'n'));
	}else if ((c >= 'A' && c <= 'M') || (c >= 'N' && c<= 'Z')){
		c = ('M' - (c - 'N'));
	}
	write(1, &c,1);
}


int	main(int ac, char *ag[])
{
	int	i;

	i = 0;
	if (ac == 2)
	{
		while (ag[1][i])
		{
			print_mirror(ag[1][i]);
			i++;
		}
	}
	write(1,"\n",1);
	return 0;
}
