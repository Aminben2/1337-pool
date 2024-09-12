#include <unistd.h>

void convert(char c){
	if ((c >= 'a' && c <= 'm') || (c >= 'A' && c <= 'M')){
		c += 13;
		write(1,&c,1);
	}
	else if ((c >= 'n' && c <= 'z') || (c >= 'N' && c <= 'Z')){
		c -= 13;
		write(1,&c,1);
	}else{
		write(1,&c,1);
	}
}

int main(int ac, char *ag[])
{
	int i;

	if (ac == 2)
	{
		i = 0;
		while (ag[1][i])
		{
			convert(ag[1][i]);
			i++;
		}
	}
	write(1, "\n",1);
}