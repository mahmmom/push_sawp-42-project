#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

# define ERROR_MESSAGE "Invalid entry. Please enter a valid number. \n INT_MIN < Number < INT_MAX\n"

typedef struct s_stack {
    int *stack;
    int size;
    int count;
} t_stack;

int	    ft_atoi(char *str);
int     is_valid_number(char *str);
void	putstr_fd(char *s, int fd);
void	error_handle();
int     check_input(int ac, char **av);
void    start_stack(int ac, char **av);


t_stack   *create_stack(int   capacity);
bool    is_full(t_stack   *stack);
bool    is_empty(t_stack  *stack);
bool    push(t_stack *stack,  int item);
bool    pop(t_stack   *stack, int *item);
bool    peekt(t_stack  *stack, int *item);
void    destroy_stack(t_stack *stack);
