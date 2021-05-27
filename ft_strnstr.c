/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agevorgy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 14:05:55 by agevorgy          #+#    #+#             */
/*   Updated: 2021/01/31 14:06:07 by agevorgy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t len2;

	if (*needle == '\0')
		return ((char *)haystack);
	len2 = ft_strlen(needle);
	while (*haystack != '\0' && len-- >= len2)
	{
		if (*haystack == *needle && ft_strncmp(haystack, needle, len2) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
