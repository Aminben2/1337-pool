int haschar(char *str,char c)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return 1;
	}
	return 0;
}
int main(int ac , char *ag[])
{
	int i;
	int j;
	char deja[1024]= {0};
	if (ac == 3)
	{
		i = 0;
		j = 0;
		while (ag[1][i])
		{
			if (haschar(ag[2] ,ag[1][i]) == 1 && haschar(deja,ag[1][i]))
			{
				write(1 ,&ag[1][i],1);
				deja[j] = ag[1][i];
				j++;
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return 0;
}