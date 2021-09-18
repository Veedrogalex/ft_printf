#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	symbol;
	char	*str;

	str = (char *)s;
	symbol = (char)c;
	while (*str != symbol)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return (str);
}
