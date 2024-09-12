#include <unistd.h>

int main(int ac, char **ag)
{
	if (ac == 2)
	{
		int i = 0;
		while (ag[1][i])
		{
			if (ag[1][i] == 'a')
			{
				write(1, "a\n", 2);
				return 0;
			}
			i++;
		}
		write(1, "\n", 2);
		return 0;
	}
	write(1, "a\n", 2);
	return 0;
}