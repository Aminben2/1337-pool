#include <stdio.h>
#include <unistd.h>

char chec_rev(char c)
{
	if (c >= 'a' && c <= 'z')
		return c - 32;
	else 
		return c + 32;
} 
int count_alpha(char *str ,char c)
{
	int i = 0;
	int count = 0;
	while (str[i])
	{
		if (str[i] == c || str[i] == chec_rev(c))
			count++;
		i++;
	}
	return count;
}

int check_alpha(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return 1;
	return 0;
}

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return i;
}

int check_is_deja(char *str, char c)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] == c || str[i] == chec_rev(c))
			return 1;
		i++;
	}
	return 0;
}

char to_lower(char c)
{
	if (c >= 'A' && c <= 'Z')
		return c + 32;
	return c;
}
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
int alpha_count(char *str)
{
	int i = 0, j = 0;
	char deja[1024];
	int count = 0;
	while (str[i])
	{
		if (!has_char(deja,str[i]) 
			&& !has_char(deja, 	(str[i]))
			&& check_alpha(str[i]))
		{
			deja[j++]= str[i];
			count++;
		}
		i++;
	}
	return count;
}

int main(int ac, char **ag)
{
	if (ac == 2)
	{
		int i = 0 , j = 0;
		char deja[1024];
		int alphaC = alpha_count(ag[1]);
		while (ag[1][i])
		{
			if (check_alpha(ag[1][i]) && !check_is_deja(deja, ag[1][i]))
			{
				printf("%d%c", count_alpha(ag[1],ag[1][i]),to_lower(ag[1][i]));
				deja[j++] = ag[1][i];
				if (j < alphaC)
					printf(", ");
			}
			i++;
		}
	}
	printf("\n");
	return 0;
}