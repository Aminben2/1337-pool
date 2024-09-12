#include <unistd.h>

int main(int ac,char *ag[]){
	int i , j, k;
	i = j = k= 0;
	if (ac == 3)
	{
		while (ag[1][i] && ag[2][j]){
			if (ag[2][j] == ag[1][i]){
				i++;
			}
			j++;
		}
		if (ag[1][i] == '\0'){
			while (ag[1][k]){
				write(1 ,&ag[1][k],1);
				k++;
			}
		}
	}
	write(1,"\n",1);
	return 0;
}