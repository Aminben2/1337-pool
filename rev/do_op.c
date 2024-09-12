#include <unistd.h>

void	console_log(char *msg);

int	ft_atoi(char *nbr)
{
	int nb = 0;
	int negative_counts = 0;
	int i = 0;
	while ((nbr[i] >= 9 && nbr[i] <= 13) || nbr[i] == 32)
		i++;
	while (nbr[i] == '-' || nbr[i] == '+')
	{
		if (nbr[i] == '-')
			negative_counts++;
		if (negative_counts > 1)
		{
			return 0;
		}
		i++;
	}
	while (nbr[i] >= '0' && nbr[i] <= '9')
	{
		nb *= 10;
		nb += nbr[i] - '0';
		i++;
	}
	if (negative_counts == 1)
		return (-nb);
	return (nb);
}

int	len(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	return i;
}


void ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_nbr(int nb)
{
	long lnb;
	lnb = nb;

	if (lnb < 0)
	{
		write(1, "-", 1);
		lnb *= -1;
	}
	if (lnb / 10)
	{
		ft_nbr(lnb / 10);
	}
	ft_putchar(lnb % 10 + '0');
}

void	console_log(char *msg)
{
	int i = 0;
	while (msg[i])
	{
		ft_putchar(msg[i]);
		i++;
	}
	ft_putchar('\n');
}
int main(int ac, char **ag)
{
	if (ac == 4)
	{
		int op_len = len(ag[2]);
		if (op_len > 1)
		{
			console_log("operator is not valid");
			return 1;
		}
		switch (ag[2][0])
		{
		case '+':
				ft_nbr(ft_atoi(ag[1]) + ft_atoi(ag[3]));
			break;
		case '-':
				ft_nbr(ft_atoi(ag[1]) - ft_atoi(ag[3]));
			break;
		case '/':
				if (ft_atoi(ag[3])){
					ft_nbr(ft_atoi(ag[1]) / ft_atoi(ag[3]));
				}else{
					console_log("Division by 0 error");
					break;
				}
		break;
		case '*':
				ft_nbr(ft_atoi(ag[1]) * ft_atoi(ag[3]));
		break;
		case '%':
				ft_nbr(ft_atoi(ag[1]) % ft_atoi(ag[3]));
		break;
		default:
			break;
		}
	}
	ft_putchar('\n');
	return 0;
}