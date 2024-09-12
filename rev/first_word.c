#include <unistd.h>

int is_space(char c)
{
	if ( c == 32 || (c >= 9 && c<= 13))
		return 1;
	return 0;
}
int main(int ac, char **ag)
{
	if (ac == 2)
	{
		int i = 0;
		while (ag[1][i])
		{
			while (is_space(ag[1][i]) && ag[1][i])
				i++;
			while (!is_space(ag[1][i]) && ag[1][i])
			{
				write(1, &ag[1][i], 1);
				i++;
			}
			break;
		}
	}
	write(1, "\n", 1);
	return 0;
}