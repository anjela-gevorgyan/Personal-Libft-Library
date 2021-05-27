/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agevorgy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 16:34:02 by agevorgy          #+#    #+#             */
/*   Updated: 2021/02/02 16:34:04 by agevorgy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	*ft_substr_split(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = (char*)malloc(sizeof(*s) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}

static char	**ft_alloc_split(char const *s, char c)
{
	size_t	i;
	char	**split;
	size_t	total;

	i = 0;
	total = 0;
	while (s[i])
	{
		if (s[i] == c)
			total++;
		i++;
	}
	split = (char**)malloc(sizeof(s) * (total + 2));
	if (!split)
		return (NULL);
	return (split);
}

static void	*ft_rng(char **t, char const *s, t_split_next *st, t_split_next *lt)
{
	size_t	i;

	t[lt->length] = ft_substr_split(s, st->start, st->length);
	if (!t[lt->length])
	{
		i = 0;
		while (i < lt->length)
		{
			free(t[i]);
			i++;
		}
		free(t);
	}
	lt->length++;
	return (t);
}

static void	*ft_split_by_char(char **split, char const *s, char c)
{
	size_t			i;
	t_split_next	st;
	t_split_next	lt;

	i = 0;
	lt.length = 0;
	lt.start = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			st.start = lt.start;
			st.length = (i - lt.start);
			if (i > lt.start && !ft_rng(split, s, &st, &lt))
				return (NULL);
			lt.start = i + 1;
		}
		i++;
	}
	st.start = lt.start;
	st.length = (i - lt.start);
	if (i > lt.start && i > 0 && !ft_rng(split, s, &st, &lt))
		return (NULL);
	split[lt.length] = 0;
	return (split);
}

char		**ft_split(char const *s, char c)
{
	char	**split;

	if (!(split = ft_alloc_split(s, c)))
		return (NULL);
	if (!ft_split_by_char(split, s, c))
		return (NULL);
	return (split);
}
