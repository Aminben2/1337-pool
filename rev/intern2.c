#include <unistd.h>

int has_char(char c,char* str)
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

int main(int ac,char *ag[]){
	int i = 0,j = 0;
	char deja[255]= {0};
	if (ac == 3)
	{
		while(ag[1][i]){
			if (has_char(ag[1][i],ag[2]) && !has_char(ag[1][i],deja)){
				write(1,&ag[1][i],1);
				deja[j] = ag[1][i] ;
				j++;
			}
			i++;
		}
	}
	write(1, "\n",1);
	return 0;
}