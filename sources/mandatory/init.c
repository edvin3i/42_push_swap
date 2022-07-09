/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 08:19:53 by gbreana           #+#    #+#             */
/*   Updated: 2022/03/31 00:16:03 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/push_swap.h"

t_node	**ps_lstcreate(void)
{
	t_node	**stack;

	stack = (t_node **) malloc(sizeof (t_node));
	if (!stack)
		exit(0);
	*stack = NULL;
	return (stack);
}

void	ps_init_stack(t_node **stack, int argc, char **argv)
{
	int		i;
	char	**tmp;
	t_node	*node;

	i = 0;
	if (argc == 2)
		tmp = ft_split(argv[1], ' ');
	else
	{
		tmp = argv;
		i = 1;
	}
	while (tmp[i])
	{
		node = ps_lstnew(ft_atoin(tmp[i]));
		ps_lstadd_back(stack, node);
		i++;
	}
	ps_set_index(stack);
	if (argc == 2)
		ps_free_str(tmp);
}
