#include "push_swap.h"

int	ft_my_atoi(char *str)
{
	long	sign;
	long	result;
	long	i;

	sign = 1;
	result = 0;
	i = 0;
	while (((str[i] >= 9 && str[i] <= 13) || str[i] == 32) && str[i])
		i++;
	if ((str[i] == '+' || str[i] == '-') && str[i])
		sign = 1 - 2 * (str[i++] == '-');
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		if ((result > LONG_MAX / 10) 
			|| (result == LONG_MAX / 10 && (str[i] - '0') > LONG_MAX % 10))
		{
			if (sign == 1)
				return (-1);
			else
				return (0);
		}
		result = 10 * result + (str[i] - '0');
		i++;
	}
	return (sign * result);
}

int is_valid_number(char *str)
{
    if (*str == '-' || *str == '+')
        str++;
    while (*str)
	{
        if (*str < '0' || *str > '9')
            return 0;
        str++;
    }
    return (1);
}

void	putstr_fd(char *s, int fd)
{
	if (s == NULL || fd < 0)
		return ;
	if (*s != '\0')
	{
		write(fd, s, 1);
		putstr_fd(s + 1, fd);
	}
}

void	error_handle()
{
		putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
}

int check_input(int ac, char **av)
{
	int i;

    i = 0;
	while  ( i < ac - 1)
	{
        if (!is_valid_number(av[i+1]))
            error_handle();
		i++;
    }
	return (1);
}
