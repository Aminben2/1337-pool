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

void ft_putstr(char *str)
{
	int i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}
int main(int ac, char **ag)
{
	int i;
	int j;
	int k;
	char str[1024];

	if (ac == 3)
	{
		k = 0;
		i = 0;
		j = 0;
		str[0]= '\0';
		while (ag[1][i])
		{
			if (has_char(str,ag[1][i]) == 0)
			{
				str[k] = ag[1][i];
				k++;
			}
			i++;
		}
		while (ag[2][j])
		{
			if (has_char(str,ag[2][j]) == 0)
			{
				str[k] = ag[2][j];
				k++;
			}
			j++;
		}
		str[k] = '\0';
		ft_putstr(str);
	}
	write(1, "\n", 1);
	return 0;
}
