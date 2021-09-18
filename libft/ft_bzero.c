#include "libft.h"

void	ft_bzero(void *str, size_t n)
{
	unsigned char *mas;

	mas = str;
	while (n > 0)
	{
		*mas = 0;
		mas++;
		n--;
	}
}
