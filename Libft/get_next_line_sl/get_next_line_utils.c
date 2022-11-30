/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marias-e <marias-e@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 12:41:41 by marias-e          #+#    #+#             */
/*   Updated: 2022/11/01 13:03:31 by marias-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(const char *str)
{
	size_t	n;

	n = 0;
	while (str[n])
		n++;
	return (n);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	size_t	n1;
	size_t	n2;
	char	*str;

	if (!s1 || !s2)
		return (0);
	n1 = ft_strlen_gnl(s1);
	str = malloc(n1 + ft_strlen_gnl(s2) + 1);
	if (!str)
		return (0);
	n2 = 0;
	while (n2 < n1)
	{
		str[n2] = s1[n2];
		n2++;
	}
	n1 = 0;
	while (s2[n1])
	{
		str[n2] = s2[n1];
		n2++;
		n1++;
	}
	str[n2] = s2[n1];
	return (str);
}

char	*ft_strdup_gnl(const char *s1)
{
	char		*str;
	size_t		n;

	str = (char *) malloc(ft_strlen_gnl(s1) + 1);
	if (!str)
		return (0);
	n = 0;
	while (s1[n])
	{
		str[n] = s1[n];
		n++;
	}
	str[n] = 0;
	return (str);
}

char	*ft_substr_gnl(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	n;

	n = 0;
	if (!s)
		return (ft_strdup_gnl(""));
	if ((size_t)start >= ft_strlen_gnl(s))
		return (ft_strdup_gnl(""));
	if ((unsigned int)len > ft_strlen_gnl(s) - (size_t)start)
		str = malloc((ft_strlen_gnl(s) - (size_t)start + 1) * sizeof(char));
	else
		str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	while (n < len && s[start])
	{
		str[n] = s[start];
		n++;
		start++;
	}
	str[n] = 0;
	return (str);
}

int	ft_strchr_mod(const char *s, int c)
{
	int	count;

	count = 0;
	while (s[count])
	{
		if (s[count] == (char)c)
			return (count);
		count++;
	}
	if (s[count] == (char)c)
		return (count);
	return (-1);
}
