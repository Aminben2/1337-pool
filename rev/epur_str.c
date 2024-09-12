#include <unistd.h>

int check_if_blank(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
	{
		return 1;
	}
	return 0;
}

int count_words(char *str)
{
	int i = 0;
	int count = 0;
	while (str[i])
	{
		while (check_if_blank(str[i]) && str[i])
		{
			i++;
		}
		if (str[i])
			count++;
		while (!check_if_blank(str[i]) && str[i])
		{
			i++;
		}
	}
	return count;
}

int main(int ac, char **ag)
{
	if ( ac == 2)
	{
		int count = count_words(ag[1]);
		int w = 0;
		int i = 0;
		while (ag[1][i])
		{
			while (check_if_blank(ag[1][i]) && ag[1][i])
			{
				i++;
			}
			if (ag[1][i])
				w++;
			while (!check_if_blank(ag[1][i]) && ag[1][i])
			{
				write(1, &ag[1][i], 1);
				i++;
			}
			if (w < count)
				write(1, " ",1);
		}
	}
	write(1, "\n",1);
	return 0;
}