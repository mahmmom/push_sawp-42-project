#include "push_swap.h"

int main(int ac, char **av)
{
    if (ac > 1)
    {
		int i = 0;
		char **str = parse_args(ac-1, av);
		while (str[i])
		{
			printf("%s\n", str[i]);
			i++;
		}
    }
    else
    {
		  putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		  exit(EXIT_FAILURE);
    }
    return (0);
}
