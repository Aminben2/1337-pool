#include <unistd.h>

int main(int ac, char **ag)
{
	if (ac > 1)
	{
		int i = 0;
		while (ag[1][i])
		{
			write(1, &ag[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return 0;
}