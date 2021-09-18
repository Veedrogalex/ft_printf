#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	symbol;
	char	*str;

	str = (char *)s + ft_strlen(s);
	symbol = (char)c;
	while (*str != symbol)
	{
		if (str == s)
			return (0);
		str--;
	}
	return (str);
}
