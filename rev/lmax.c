#include <stdio.h>
int		max(int* tab, unsigned int len){
	unsigned int i,j;
	int tmp;
	i  = 0;
	while (i < len - 1){
		j = 0;
		while (j < len - i){
			if (tab[j] > tab[j+1]){
				tmp = tab[j];
				tab[j] = tab[j+1];
				tab[j+1] = tmp;
			}
			j++;
		}
		i++;
	}
	return (int)tab[len - 1];
}

int main() {
    int arr[] = {5,2,7,4,1};
    unsigned int len = 5;

    int max_value = max(arr, len);
    printf("The maximum value in the array is: %d\n", max_value);

    return 0;
}