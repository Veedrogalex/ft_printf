#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*ch;
	size_t		i;

	i = 0;
	ch = (char*)malloc((ft_strlen(s1) * sizeof(char)) + 1);
	if (ch == NULL)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		ch[i] = s1[i];
		i++;
	}
	ch[i] = '\0';
	return (ch);
}
