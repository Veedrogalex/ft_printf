#include "libft.h"

int			ft_atoi(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == 32 || *str == '\t' || *str == '\n'
			|| *str == '\r' || *str == '\v' || *str == '\f')
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		if (result > 2147483647 && sign == 1)
			return (-1);
		if (result > 2147483648 && sign == -1)
			return (0);
		str++;
	}
	return (result * sign);
}
