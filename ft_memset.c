/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agevorgy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 14:09:11 by agevorgy          #+#    #+#             */
/*   Updated: 2021/01/27 17:41:03 by agevorgy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*ptr;

	ptr = (char *)b;
	while (len > 0)
	{
		ptr[len - 1] = c;
		len--;
	}
	return (b);
}
