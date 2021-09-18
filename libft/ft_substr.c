#include "libft.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ret;
	unsigned int	i;
	unsigned int	j;
	unsigned int	lens;

	if (!s)
		return (NULL);
	j = 0;
	lens = ft_strlen(s);
	if (start >= lens)
	{
		ret = (char *)malloc(1 * sizeof(char));
		ret[0] = '\0';
		return (ret);
	}
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	ret = (char *)malloc((len + 1) * sizeof(*s));
	if (!ret)
		return (NULL);
	i = start;
	while (j < len && s[i])
		ret[j++] = s[i++];
	ret[j] = '\0';
	return (ret);
}
