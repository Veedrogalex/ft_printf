#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*mapi;
	unsigned int	i;

	i = 0;
	mapi = 0;
	if (!s || !f)
		return (NULL);
	if (!(mapi = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		mapi[i] = f(i, (char)s[i]);
		i++;
	}
	mapi[i] = '\0';
	return (mapi);
}
