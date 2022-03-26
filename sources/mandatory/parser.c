/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:00:17 by gbreana           #+#    #+#             */
/*   Updated: 2022/03/24 14:00:23 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/push_swap.h"

char	**ft_getstring(int ac, char **av)
{
	char	*tmp;
	char	**ret;
	int		i;

	tmp = NULL;
	ret = NULL;
	if (ac == 2)
		tmp = ft_strdup(av[1]);
	else if (ac > 2)
	{
		i = 1;
		while (i < ac)
		{
			tmp = ft_strnjoin(tmp, av[i]);
			if (av[++i])
				tmp = ft_strjoin(tmp, " ");
		}
	}
	ret = ft_split(tmp, ' ');
	free(tmp);
	return (ret);
}

char	**ft_parser(int ac, char **av)
{
	char	**ret;

	ret = NULL;
	if (ac < 2)
		exit(0);
	ret = ft_getstring(ac, av);
	validation(ret);
	return (ret);
}
