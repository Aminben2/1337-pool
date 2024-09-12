#include <unistd.h>

int has_char(char *str, char c)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return 1;
		i++;
	}
	return 0;
}
int main(int ac, char **ag)
{
	int i,k;

	char str[1024];

	if (ac == 3)
	{
		i = k = 0;
		while (ag[1][i])
		{
			if (has_char(ag[2],ag[1][i]) && !(has_char(str,ag[1][i])))
			{
				write(1, &ag[1][i], 1);
				str[k] = ag[1][i];
				k++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return 0;
}