#include <unistd.h>
int has_char(char *str,char c){
	int i = 0;
	while (str[i]){
		if (str[i] == c)
			return 1;
		i++;
	}
	return 0;
}
int main(int ac, char **ag){
	int i;
	int j;
	char deja_exists[1024];

	if (ac == 3)
	{
		j = 0;
		i = 0;
		while (ag[1][i]){
			if (has_char(ag[2],ag[1][i]) == 1 && has_char(deja_exists,ag[1][i]) == 0){
				write(1,&ag[1][i],1);
				deja_exists[j] = ag[1][i];
				j++;
			}
			i++;
		}
	}
	write(1,"\n",1);
	return 0;
}