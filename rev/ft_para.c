#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}
void ft_putstr(char *str)
{
	int i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}
int check_para(char *str)
{
	int i = 0;
	int len = 0;
	while (str[len])
		len++;
	while (str[i])
	{
		if (str[i] != str[len - 1 - i] )
			return 0;
		i++;
	}
	return 1;
}
int main(int ac, char **ag)
{
	if (ac > 1)
	{	
		int i = 0;
		while (ag[i])
		{
			if (check_para(ag[i]))
			{
				ft_putstr(ag[i]);
				ft_putchar('\n');
			}
			i++;
		}
	}
	write(1, "\n", 1);
}