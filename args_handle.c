#include "libft/libft.h"
#include "push_swap.h"

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
	printf("%s", arg);
	split = ft_split(arg, ' ');
	return (split);
}