int main(int ac, char *ag[])
{
	int i = 0;
	int j = 0;
	int len = 0;
	if ( ac == 3){
		while(ag[1][i] && ag[2][j]){
			if (ag[1][i] == ag[2][j])
				j++;
			i++;
		}
		if(ag[1][i] == '\0'){
			while(ag[1][len]){
				write(1,&ag[1][len],1);
				len++;
			}
		}
	}
	write(1,&ac,1);
	return 0;
}
