#include <unistd.h>
int str_len(char *str){
	int i = 0;
	while (str[i]){
		i++;
	}
	return i;
}
int main(int ac, char *ag[]){
	int	i = 0;
	if(ac == 4){
		if (str_len(ag[2]) == 1 && str_len(ag[3]) == 1){
			while (ag[1][i]){
				if (ag[1][i] == ag[2][0]){
					write(1,&ag[3][0],1);
				}else {
					write(1,&ag[1][i],1);
				}
				i++;
			}
		}
	}
	write(1, "\n", 1);
}