/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gbreana <gbreana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:18:20 by gbreana           #+#    #+#             */
/*   Updated: 2022/03/30 15:19:27 by gbreana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
#include "../../include/push_swap.h"

void	ps_lstadd_back(t_node **stack, t_node *node)
{
	t_node	*result;

	if (!*stack)
	{
		*stack = node;
		(*stack)->next = NULL;
	}
	else
	{
		result = ps_lstlast(*stack);
		result->next = node;
		node->next = NULL;
	}
}

int	ps_lstsize(t_node *stack)
{
	int		len;
	t_node	*node;

	len = 0;
	node = stack;
	while (node)
	{
		len++;
		node = node->next;
	}
	return (len);
}

int	ps_movescount(t_node **stack, int index)
{
	t_node	*node;
	int		count;

	node = *stack;
	count = 0;
	while (node)
	{
		if (node->index == index)
			break ;
		node = node->next;
		count++;
	}
	return (count);
}
