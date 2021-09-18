#include "libft.h"

int	ft_isalpha(int symbol)
{
	if ((symbol >= 'a' && symbol <= 'z') || (symbol >= 'A' && symbol <= 'Z'))
		return (1);
	return (0);
}
