#include <unistd.h>
int main(int ac, char **ag)
{
	int i,j;
	j = i = 0;

	if (ac == 3)
	{
		while (ag[1][i])
		{
			if (ag[1][i] == ag[2][j])
				i++;
			if (ag[2][j] == '\0')
			{
				write(1, "0", 1);
				return 0;
			}
			j++;
		}
		if (ag[1][j] == '\0')
		{
			write(1, "1", 1);
			return 0;
		}
	}
	write(1, "\n",1);
	return 0;
}