/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 14:13:33 by gbreana           #+#    #+#             */
/*   Updated: 2021/10/15 19:32:41 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/libft.h"

char	*ft_strdup(char *src)
{
	size_t	src_size;
	char	*dest;
	char	*iter;

	src_size = ft_strlen(src) + 1;
	dest = malloc(src_size);
	iter = dest;
	if (dest == NULL)
		return (NULL);
	while (*src)
	{
		*iter = *src;
		iter++;
		src++;
	}
	*iter = 0;
	return (dest);
}
