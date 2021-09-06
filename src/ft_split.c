/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hnewman <hnewman@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 12:52:23 by hnewman           #+#    #+#             */
/*   Updated: 2021/09/06 19:03:00 by hnewman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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
	while (src[i] && src[i] != c)
		i++;
	buf = malloc(sizeof(char) * (i + 1));
	if (!buf)
		return (NULL);
	i = 0;
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

int	init(int *i, int *j, char const *s)
{
	*i = 0;
	*j = 0;
	if (!s)
		return (1);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;
	int		num;

	if (init(&i, &j, s))
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
	arr[i] = NULL;
	return (arr);
}
