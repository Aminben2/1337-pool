#include <unistd.h>

int check_char(char c)
{
	if (c >= 'a' && c <= 'z')
		return 1;
	else if (c >= 'A' && c <= 'Z')
		return 0;
	return 2;
}
void repeat(char c, int index)
{
	while (index >= 0)
	{
		write(1, &c,1);
		index--;
	}
}
int main(int ac, char **ag)
{
	if (ac == 2)
	{
		int i = 0;
		int index;
		while (ag[1][i])
		{
			if (check_char(ag[1][i]) == 1)
			{
				index = ag[1][i] - 'a';
				repeat(ag[1][i],index);
			}
			else  if (check_char(ag[1][i]) == 0)
			{
				index = ag[1][i] - 'A';
				repeat(ag[1][i],index);
			}
			else 
				write(1, &ag[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return 0;
}