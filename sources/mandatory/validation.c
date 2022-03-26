/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 12:25:43 by gbreana           #+#    #+#             */
/*   Updated: 2022/03/25 12:25:50 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/push_swap.h"

int	is_allnums(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]))
				err_handler();
			j++;
		}
		i++;
	}
	return (0);
}

int	is_nodup(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = i + 1;
		while (str[j])
		{
			if (ft_atoin(str[i]) == ft_atoin(str[j]))
				err_handler();
			j++;
		}
		i++;
	}
	return (0);
}

int	is_sorted(char **str)
{
	int i;

	i = 0;
	while (str[i + 1])
	{
		if (ft_atoi(str[i]) < ft_atoi(str[i + 1]))
			i++;
		else
			return (0);
	}
	exit(0);
}

int	validation(char **str)
{
	is_allnums(str);
	is_nodup(str);
	is_sorted(str);
	return (0);
}
