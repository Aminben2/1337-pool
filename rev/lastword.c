#include <unistd.h>
int str_len(char *str)
{
	int i = 0;
	while (str[i])
	{
		i++;
	}
	return i;
}
int main(int ac, char **ag)
{
	int i;
	int arg_len;
	if (ac == 2)
	{
		arg_len = str_len(ag[1]);
		i = arg_len - 1;
		while ((ag[1][i] && (ag[1][i] >= 9 && ag[1][i] <= 13 )) || ag[1][i] == 32)
		{
			i--;
		}
		while (ag[1][i] && (ag[1][i] > 32 && ag[1][i] < 127))
		{
			i--;
		}
		i++;
		while (ag[1][i] && (ag[1][i] > 32 && ag[1][i] < 127))
		{
			write(1, &ag[1][i], 1);
			i++;
		}
	}
	write(1,"\n",1);
	return 0;
}