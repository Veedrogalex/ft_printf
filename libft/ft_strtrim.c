#include "libft.h"

static int		ft_check(char sym, char const *cut)
{
	int	i;

	i = 0;
	if (sym)
	{
		while (cut[i])
		{
			if (sym == cut[i])
				return (1);
			i++;
		}
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	i;
	unsigned int	left;
	unsigned int	right;
	char			*ret;

	if (!s1)
		return (NULL);
	if (s1[0] == '\0')
		return ((char *)s1);
	left = 0;
	right = ft_strlen(s1) - 1;
	while (ft_check((char)s1[left], set) == 1 && s1[left])
		left++;
	while (ft_check((char)s1[right], set) == 1 && right > left)
		right--;
	if (!(ret = (char *)malloc(sizeof(char) * (right - left + 2))))
		return (NULL);
	i = 0;
	ret[i] = (char)s1[left];
	while (left <= right)
	{
		ret[++i] = (char)s1[++left];
	}
	ret[i] = '\0';
	return (ret);
}
