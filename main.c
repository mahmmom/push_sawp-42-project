#include "push_swap.h"

int main(int ac, char **av)
{
    if (ac > 1 && check_input(ac, av))
    {
      start_stack(ac-1, av);
    }
    else
    {
		  putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		  exit(EXIT_FAILURE);
    }
    return (0);
}
