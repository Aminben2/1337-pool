#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int check_how_many_to_find(char *str,char *to_find)
{
	int i = 0, j , count = 0;
	while(str[i])
	{
		j = 0;
		while(str[i] && to_find[j] == str[i])
		{
			i++;
			j++;
		}
		if (to_find[j] == '\0')
			count++;
		i++;
	}
	return count;
}

char *ft_strreplace(char *str, char *to_find, char *to_replace)
{
	char *res;
	char *strstr_res = strstr(str, to_find);
	if (*to_find == '\0' || to_find == NULL || strstr_res == NULL)
	{
		return strdup(str);
	}
	int to_find_len = strlen(to_find);
	int to_replace_len = strlen(to_replace);
	int str_len = strlen(str);
	int to_find_times = check_how_many_to_find(str, to_find);
	res = malloc(str_len - (to_find_len * to_find_times) + (to_replace_len * to_find_times) + 1);
	
	int i = 0, j , k = 0;
	while(str[i])
	{
		if (str[i] == to_find[0])
		{
			j = 0;
			while(j < to_replace_len)
			{
				res[k] = to_replace[j];
				j++;
				k++;
			}
			i += to_find_len;
		}
		else
		{
			res[k++] = str[i++];
		}
	}
	res[i] = '\0';
	return res;
}

int main(void)
{
	char str[] = "hello world, welcome to the world of C";
	char *res = ft_strreplace(str,"world", "universe");
	printf("%s\n", res);
	free(res);
	return 0;
}