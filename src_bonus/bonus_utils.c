#include "../includes/pipex.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return ((char *)s2);
	if (!s2)
		return ((char *)s1);
	str = (char *)malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (!str)
		return (NULL);
	while (i < (size_t)ft_strlen((char *)s1))
		str[j++] = s1[i++];
	i = 0;
	while (i < (size_t)ft_strlen((char *)s2))
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t			i;
	unsigned char	*t;
	unsigned char	*u;

	i = 0;
	t = (unsigned char *)s1;
	u = (unsigned char *)s2;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return (t[i] - u[i]);
		if (!s1 || !s2)
			return (t[i] - u[i]);
		if (s1[i] == '\0' && s2[i] == '\0')
			return (t[i] - u[i]);
		i++;
	}
	return (0);
}

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	fd_close(int i, int *fd)
{
	if (i > 0)
		close(fd[0]);
	close(fd[1]);
}
