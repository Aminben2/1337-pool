// int    check_char(char q, int base)
// {
//     char b1[] = "0123456789abcdef";
//     char b2[] = "0123456789ABCDEF";

//     int i  = 0;
//     while (i < base)
//     {
//         if (b1[i] == q || b2[i] == q)
//             return (i);
//         i++;
//     }
//     return (-1);
// }

// int    ft_atoi_base(const char *str, int str_base)
// {
//     int    res;
//     int    sin;
//     int    a;

//     a = 0;
//     res = 0;
//     sin = 1;
//     while (str[a] <= 32)
//         a++;
//     if (str[a] == '-' || str[a] == '+')
//     {
//         if (str[a] == '-')
//             sin = -1;
//         a++;
//     }
//     while (check_char(str[a], str_base) != -1)
//     {
//         res = res * str_base + check_char(str[a], str_base);
//         a++;
//     }
//     return (res * sin);
// }








#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int check_is_exists(char c, int base)
{
    char base1[] = "0123456789abcdef";
    char base2[] = "0123456789ABCDEF";
    int i = 0;
    while(i < base)
    {
        if (base1[i] == c || base2[i] == c)
            return (i);
        i++;
    }
    return -1;
}

int ft_atoi_base(const char *str, int base)
{
    int number = 0;
    int signs = 1;
    int i = 0 ;

    while(str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            signs *= -1;
        i++;
    }
    while(check_is_exists(str[i], base) != -1)
    {
        number = number * base + check_is_exists(str[i], base);
        i++;
    }
    return number * signs;
}


char *ft_itoa(int nbr)
{
    long tmp = nbr;
    char *str;
    int len = (nbr < 0 ? 2 : 1);
    while(nbr && ++len)
        nbr /= 10;
    str = malloc(len);
    if (!str)
        return NULL;
    str[--len] = '\0';
    if (tmp <= 0)
    {
        str[0] = (tmp < 0 ? '-' : '0');
        tmp  *= -1;
    }
    while(tmp)
    {
        str[--len] = tmp % 10 + '0';
        tmp /= 10;
    }
    return str;
}

int main(void)
{
    // printf("%d",ft_atoi_base("7f",16));
    printf("%s",ft_itoa(INT_MIN));
    return 0;
}