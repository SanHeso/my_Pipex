/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 12:52:23 by hnewman           #+#    #+#             */
/*   Updated: 2021/09/01 18:36:24 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static size_t	ft_strlen_c(char const *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static char	**memfree(char **s, int p)
{
	while (p >= 0)
	{
		free(s[p]);
		p--;
	}
	free(s);
	return (NULL);
}

static char	*ft_strdup_c(char const *src, char c)
{
	int		i;
	char	*buf;

	i = 0;
	buf = malloc(sizeof(char) * (ft_strlen_c(src, c) + 1));
	if (!buf)
		return (NULL);
	while (src[i] && src[i] != c)
	{
		buf[i] = src[i];
		i++;
	}
	buf[i] = '\0';
	return (buf);
}

static int	qua_word(char const *s, char c)
{
	int	t;
	int	len;

	t = 0;
	len = 0;
	while (s[t])
	{
		while (s[t] && s[t] == c)
			t++;
		if (s[t] && s[t] != c)
		{
			while (s[t] && s[t] != c)
				t++;
			len++;
		}
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;
	int		num;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	num = qua_word(s, c);
	arr = malloc(sizeof(char *) * (num + 1));
	if (!arr)
		return (NULL);
	while (num--)
	{
		while (s[j] && s[j] == c)
			j++;
		arr[i] = ft_strdup_c(&s[j], c);
		if (!arr[i])
			return (memfree(arr, i--));
		while (s[j] && s[j] != c)
			j++;
		i++;
	}
	return (arr);
}
