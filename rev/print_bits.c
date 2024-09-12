#include <unistd.h>

void	printf_bits(unsigned char octet)
{
	int i = 7;
	while(i >= 0)
	{
		if((octet >> i) & 1)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		i--;
	}
}

unsigned char swap_bits(unsigned char octet)
{
	return (octet >> 4 | octet << 4);
}

unsigned char reverse_bits(unsigned char o)
{
	return ((((o >> 0) & 1) << 7) |
			(((o >> 1) & 1) << 6) |
			(((o >> 2) & 1) << 5) |
			(((o >> 3) & 1) << 4) |
			(((o >> 4) & 1) << 3) |
			(((o >> 5) & 1) << 2) |
			(((o >> 6) & 1) << 1) |
			(((o >> 7) & 1) << 0) );
}

int main(void)
{
	//printf_bits(2);
	printf_bits(reverse_bits(2));
	return 0;
}