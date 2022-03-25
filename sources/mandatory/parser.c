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

char	**ft_getstring(struct s_input input)
{
	char	*tmp;
	char	**ret;
	int		i;

	tmp = NULL;
	if (input.argc == 2)
		tmp = ft_strdup(input.argv[1]);
	else if (input.argc > 2)
	{
		i = 1;
		while (i < input.argc)
		{
			tmp = ft_strnjoin(tmp, input.argv[i]);
			if (input.argv[++i])
				tmp = ft_strjoin(tmp, " ");
		}
	}
	ret = ft_split(tmp, ' ');
	return (ret);
}

char	**ft_parser(struct s_input input)
{
	char	**ret;

	ret = NULL;
	ret = ft_getstring(input);
	return (ret);
}
