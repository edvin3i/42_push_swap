/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:18:32 by gbreana           #+#    #+#             */
/*   Updated: 2022/03/30 15:19:27 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/push_swap.h"

t_node	*ps_lstnew(int num)
{
	t_node	*result;

	result = (t_node *)malloc(sizeof(t_node));
	if (!result)
		return (NULL);
	result->num = num;
	result->index = -1;
	result->next = NULL;
	return (result);
}

t_node	*ps_lstlast(t_node *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

t_node	*ps_next_min(t_node **stack)
{
	int		flag;
	t_node	*node;
	t_node	*min;

	flag = 0;
	node = *stack;
	min = NULL;
	if (node)
	{
		while (node)
		{
			if ((node->index < 0) && \
			(!flag || (node->num < min->num)))
			{
				min = node;
				flag = 1;
			}
			node = node->next;
		}
	}
	return (min);
}

void	ps_set_index(t_node **stack)
{
	int		index;
	t_node	*node;

	index = 0;
	node = ps_next_min(stack);
	while (node)
	{
		node->index = index++;
		node = ps_next_min(stack);
	}
}
