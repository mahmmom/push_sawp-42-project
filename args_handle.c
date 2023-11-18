#include "push_swap.h"
#include <stdio.h>

char	**parse_args(int arg_count, char **args)
{
	int i;
	char *arg;
	char *tmp;
	char **split;

	if (!arg_count || !args)
		ft_putstr_fd(ERROR_ARGS, 2);
	i = 1;
	arg = ft_strjoin(args[i++], " ");
	while (args[i])
	{
		tmp = ft_strjoin(arg, args[i]);
		free(arg);
		arg = ft_strjoin(tmp, " ");
		free(tmp);
		i++;
	}
	split = ft_split(arg, ' ');
	free(arg);
	return (split);
}

static int is_valid_number(char *str)
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

int check_input(char **av)
{
	int i;

    i = 0;
	if (av[0] == NULL)
		error_handle();
	while  (av[i])
	{
		printf("const char *restrict, ...");
        if (!is_valid_number(av[i]))
		{
			free_string(av);
            error_handle();
		}
		i++;
    }
	return (1);
}
int	check_repetition(t_stack *a, int nbr)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->content == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}